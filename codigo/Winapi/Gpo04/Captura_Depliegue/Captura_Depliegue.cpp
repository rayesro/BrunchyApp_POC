#include <Windows.h>
#include "resource.h"
#include <string>
#include <fstream>
#include <filesystem>


using namespace std;


int contador = 0;
HINSTANCE GlobalhIdentificador;
wchar_t* rutaDeImageEnDisco = new wchar_t[255];
HBITMAP IMGDEFAULT;

#define USUARIO_ADMIN  1 
#define USUARIO_CAJERO 2

struct Usuario {
	string Nombre;
	string Contrasena;
	char RutaImagen[MAX_PATH];

	int TipoUsuario;
	Usuario* Siguiente;
};

Usuario* INICIO_LISTA = NULL;
Usuario* UsuarioEnSesion = NULL;

INT_PTR CALLBACK fnDlgInicioSesion (HWND hDialogoActual, UINT uMensaje,			WPARAM wParam,			LPARAM lParam				);

void GuardarUsuariosEnArchivo()
{
	fstream archivo;
	archivo.open("usuarios.bin", ios::binary | ios::out);

	Usuario* usuario = INICIO_LISTA;
	while (usuario != NULL)
	{
		archivo.write((char*)usuario, sizeof(Usuario));

		usuario = usuario->Siguiente;
	}
	archivo.close();
}

void GuardarUsuariosEnCSV()
{
	fstream archivo; // Comma Separated Values
	archivo.open("usuarios.csv", ios::out);

	Usuario* us = INICIO_LISTA;
	while (us != NULL)
	{
		archivo << us->Nombre			 << ","
						<< us->Contrasena	 << ","
						<< us->TipoUsuario << ","
						<< us->RutaImagen  << "\n";

		us = us->Siguiente;
	}
	archivo.close();
}

void LeerUsuariosDesdeArchivo()
{
	fstream archivo;
	archivo.open("usuarios.bin", ios::binary | ios::in | ios::ate); //at the end

	if (archivo.is_open())//es validar que el archivo exista y que haya sido abierto correctamente
	{
		int tamanoDeArchivo = archivo.tellg(); //tellg devuelve la posicion del cursor
		int totalDeUsuarios = tamanoDeArchivo / sizeof(Usuario);

		for (int i = 0; i < totalDeUsuarios; i++)
		{
			archivo.seekg(i * sizeof(Usuario)); // seekg establecemos la posicion del cursor

			Usuario* temp = new Usuario;
			archivo.read((char*)temp, sizeof(Usuario));
			temp->Siguiente = NULL;

			if (INICIO_LISTA == NULL)
			{
				INICIO_LISTA = temp;
			}
			else
			{
				Usuario* aux = INICIO_LISTA;
				while (aux->Siguiente != NULL)
				{
					aux = aux->Siguiente;
				}
				aux->Siguiente = temp;
			}
		}
	}
	archivo.close();
}

void MostrarMensajeDeCierre()
{
	int respuesta = MessageBoxA(
		NULL,
		"Estas seguro que quieres cerrar la aplicacion?", 
		"Terminando aplicacion...", 
		MB_OKCANCEL | MB_ICONQUESTION);
	if (respuesta == IDOK) //si el usuario le dio click al boton de aceptar en el Messagebox
	{
		GuardarUsuariosEnArchivo();
		PostQuitMessage(0);
	}
}

Usuario* ObtenerUsuarioSeleccionado(HWND hDialogoActual)
{
	int indice = SendDlgItemMessage(hDialogoActual, LBX_USUARIOS, LB_GETCURSEL, NULL, NULL);
	Usuario* usuarioSeleccionado = 
		(Usuario*)SendDlgItemMessage(hDialogoActual, LBX_USUARIOS, LB_GETITEMDATA, indice, NULL);
	return usuarioSeleccionado;
}

INT_PTR CALLBACK fnDlgPantallaPrincipal(HWND hDialogoActual, UINT uMensaje, WPARAM wParam, LPARAM lParam)
{
	switch (uMensaje)
	{
	case WM_INITDIALOG:
	{
		SetDlgItemTextA(hDialogoActual, LBL_NOMBREUSUARIO, UsuarioEnSesion->Nombre.c_str());

		HWND hPicImagen = GetDlgItem(hDialogoActual, PIC_IMAGEN);
		SendMessage(hPicImagen, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)IMGDEFAULT);

		//Establecemos la imagen del usuario en sesion en el picture control

		//Checar si la ruta de la imagen del usuario en sesion esta vacia
		//Si esta vacia cargo la IMGDEFAULT
		//Si no, cargo la imagen usando la ruta de la imagen

		HBITMAP img = (HBITMAP)LoadImageA(GlobalhIdentificador, UsuarioEnSesion->RutaImagen, IMAGE_BITMAP, 32, 32, LR_LOADFROMFILE);
		HWND hPictureControl = GetDlgItem(hDialogoActual, PIC_IMAGENUSUARIO);
		SendMessage(hPictureControl, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)img);


		//Los siguientes pasos son para inicializar el listbox
		//1-Obtener la referencia al componente del Listbox, en este caso, al ID LBX_USUARIOS
		HWND hListbox = GetDlgItem(hDialogoActual, LBX_USUARIOS);
		Usuario* aux = INICIO_LISTA;
		while (aux != NULL)
		{
			//2-Mandar un mensaje para agregar una cadena de texto al listbox usando su HWND y 
			//3-Guardar el indice que regresa la funcion SendMessageA
			int indice = SendMessageA(hListbox, LB_ADDSTRING, 0, (LPARAM)aux->Nombre.c_str());
			//4-Usar el indice para establecer datos dentro del listbox
			SendMessage
			(
				hListbox,				//la referencia al listbox ya que a ese listbox vamos a mandar el mensaje
				LB_SETITEMDATA, //Establece datos en un registro del listbox
				indice,					//indice del listbox donde va a guardar los datos
				(LPARAM)aux			//los datos a guardar
			);
			aux = aux->Siguiente;
		}
		if (UsuarioEnSesion->TipoUsuario == USUARIO_ADMIN)
		{
			HMENU menu = LoadMenu(GlobalhIdentificador, MAKEINTRESOURCE(IDR_MENU1));
			SetMenu(hDialogoActual, menu);
		}
		else
		{
			HMENU menu = LoadMenu(GlobalhIdentificador, MAKEINTRESOURCE(IDR_MENU2));
			SetMenu(hDialogoActual, menu);
		}
	}
	break;
	case WM_CLOSE:
	{
		MostrarMensajeDeCierre();
	}
	break;
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case ID_CERRARSESIONUsuario:
		{
			int respuesta = MessageBoxA(
				NULL,
				"Estas seguro que quieres cerrar sesion?",
				"Cerrando sesion...",
				MB_OKCANCEL | MB_ICONQUESTION);
			if (respuesta == IDOK) //si el usuario le dio click al boton de aceptar en el Messagebox
			{
				HWND hDlg = CreateDialogW(GlobalhIdentificador, MAKEINTRESOURCE(DLG_INICIOSESION), NULL, fnDlgInicioSesion);
				ShowWindow(hDlg, SW_SHOW);
				DestroyWindow(hDialogoActual);

			}
		}
		case BTN_GUARDARCSV:
		{
			GuardarUsuariosEnCSV();
		}
		break;
		case BTN_ELIMINAR: // codigo para eliminar un usuario
		{
			int indice = SendDlgItemMessage(hDialogoActual, LBX_USUARIOS, LB_GETCURSEL, NULL, NULL);
			Usuario* usuarioAEliminar = (Usuario*)SendDlgItemMessage(hDialogoActual, LBX_USUARIOS, LB_GETITEMDATA, indice, NULL);

			string texto = "Deseas eliminar el usuario \"" + usuarioAEliminar->Nombre + "\"?";
			int respuesta = MessageBoxA(
				NULL,
				texto.c_str(),
				"Borrando datos",
				MB_OKCANCEL | MB_ICONQUESTION
			);

			if (respuesta == IDOK) //si el usuario le dio click al boton de aceptar en el Messagebox
			{
				Usuario* usuarioQueSeVaAEliminar = NULL;
				//Para eliminar un nodo de la lista hay 3 escenarios:
				//Cuando el nodo esta al principio, en medio o al final de la lista
				if (usuarioAEliminar == INICIO_LISTA)
				{
					usuarioQueSeVaAEliminar = INICIO_LISTA;
					INICIO_LISTA = INICIO_LISTA->Siguiente;
				}
				else if (usuarioAEliminar->Siguiente == NULL)
				{
					Usuario* aux = INICIO_LISTA;
					while (aux->Siguiente != usuarioAEliminar)
					{
						aux = aux->Siguiente;
					}
					usuarioQueSeVaAEliminar = aux->Siguiente;
					aux->Siguiente = NULL;
				}
				else
				{
					Usuario* aux = INICIO_LISTA;
					while (aux->Siguiente != usuarioAEliminar)
					{
						aux = aux->Siguiente;
					}
					usuarioQueSeVaAEliminar = aux->Siguiente;
					aux->Siguiente = usuarioAEliminar->Siguiente;
				}

				usuarioQueSeVaAEliminar = NULL;

				SendDlgItemMessage(hDialogoActual, LBX_USUARIOS, LB_DELETESTRING, indice, 0);
			}
		}
		break;
		case BTN_GUARDAR: // codigo para modificar/editar un usuario
		{
			char nombreDeUsuario[50], contrasena[50];
			GetDlgItemTextA(hDialogoActual, TXT_NOMUS, nombreDeUsuario, 50);
			GetDlgItemTextA(hDialogoActual, TXT_CONTRAUS, contrasena, 50);

			//Convertimos los arreglos de chars a datos tipo string
			string nombreDeUsuarioStr(nombreDeUsuario);
			string contrasenaStr(contrasena);

			int indice = SendDlgItemMessage(hDialogoActual, LBX_USUARIOS, LB_GETCURSEL, NULL, NULL);
			if (indice == -1)
			{
				MessageBoxA(
					NULL,
					"Selecciona un usuario antes, por favor",
					"Atencion...",
					MB_OK | MB_ICONEXCLAMATION);
				break;
			}



			Usuario* usuarioAEditar = (Usuario*)SendDlgItemMessage(hDialogoActual, LBX_USUARIOS, LB_GETITEMDATA, indice, NULL);

			usuarioAEditar->Nombre = nombreDeUsuarioStr;
			usuarioAEditar->Contrasena = contrasenaStr;

			SendDlgItemMessage(hDialogoActual, LBX_USUARIOS, LB_DELETESTRING, indice, 0);
			
			HWND hListbox = GetDlgItem(hDialogoActual, LBX_USUARIOS);
			indice = SendMessageA(hListbox, LB_ADDSTRING, 0, (LPARAM)usuarioAEditar->Nombre.c_str());
			SendMessage(hListbox, LB_SETITEMDATA, indice, (LPARAM)usuarioAEditar);

		}
		break;
		case BTN_CARGARIMAGEN:
		{
			OPENFILENAME ofn;
			ZeroMemory(&ofn, sizeof(OPENFILENAME));

			ofn.hwndOwner = hDialogoActual;					// definimos el dialogo padre
			ofn.lStructSize = sizeof(OPENFILENAME); // tamano de la estructura
			ofn.lpstrFile = rutaDeImageEnDisco;			// aqui se guarda el nombre/ruta de la imagen
			ofn.nMaxFile = 255;											// longitud del nombre del archivo
			ofn.lpstrDefExt = L"bmp";								//extension de archivos de imagen a manejar
			ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_NOCHANGEDIR;
			ofn.lpstrFilter = L"Imagenes BMP\0*.bmp";

			if (GetOpenFileName(&ofn))
			{
				//cargar la imagen de mapa de bits en memoria
				HBITMAP bitmap = (HBITMAP)LoadImage(GlobalhIdentificador, rutaDeImageEnDisco, IMAGE_BITMAP, 128, 128, LR_LOADFROMFILE);
				//obtengo la referencia al picture control - PIC_IMAGEN
				HWND hPictureControl = GetDlgItem(hDialogoActual, PIC_IMAGEN);
				//Enviar la imagen al control
				SendMessage(hPictureControl, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bitmap);
			}

		}
		break;
		case BTN_NUEVO: // codigo para dar de alta un nuevo usuario
		{
			//obtenemos los datos de la pantalla
			char nombreDeUsuario[50], contrasena[50];
			GetDlgItemTextA(hDialogoActual, TXT_NOMUS, nombreDeUsuario, 50);
			GetDlgItemTextA(hDialogoActual, TXT_CONTRAUS, contrasena, 50);

			//Convertimos los arreglos de chars a datos tipo string
			string nombreDeUsuarioStr(nombreDeUsuario);
			string contrasenaStr(contrasena);

			//craemos un usuario y le asignamos los datos de la pantalla
			Usuario* nuevoUsuario = new Usuario;
			nuevoUsuario->Nombre = nombreDeUsuarioStr;
			nuevoUsuario->Contrasena = contrasenaStr;
			nuevoUsuario->TipoUsuario = USUARIO_CAJERO;
			nuevoUsuario->Siguiente = NULL;

			//empieza conversion de wchar_t a char

			//Si la rutaDeImageEnDisco esta vacia entonces 
			//guardamos la ruta de la imagen default en la RutaImagen
			//Si rutaDeImageEnDisco si tiene informacion entonces
			//hacemos todo la conversion de wchar_t a char[]
			wstring ws = wstring(rutaDeImageEnDisco);
			string imagen(ws.begin(), ws.end());
			strcpy(nuevoUsuario->RutaImagen, imagen.c_str());
			//termina conversion de wchar_t a char
			

			//metemos al usuario nuevo en la lista
			if (INICIO_LISTA == NULL)
			{
				INICIO_LISTA = nuevoUsuario;
			}
			else
			{
				Usuario* aux = INICIO_LISTA;
				while (aux->Siguiente != NULL)
				{
					aux = aux->Siguiente;
				}
				aux->Siguiente = nuevoUsuario;
			}

			//metemos al nuevo usuario en el listbox
			HWND hListbox = GetDlgItem(hDialogoActual, LBX_USUARIOS);
			int indice = SendMessageA(hListbox, LB_ADDSTRING, 0, (LPARAM)nuevoUsuario->Nombre.c_str());
			SendMessage(hListbox, LB_SETITEMDATA, indice, (LPARAM)nuevoUsuario);
		}
		break;
		//5-Agregamos el codigo para manejar el evento cuando le demos click a cualquiera de los registros del listbox
		case LBX_USUARIOS:
		{
			switch (HIWORD(wParam))
			{
			case LBN_SELCHANGE:
			{
				//6-Obtener el indice del registro del listbox al que le dimos click
				int indice = SendDlgItemMessage(hDialogoActual, LBX_USUARIOS, LB_GETCURSEL, NULL, NULL);
				//7-Obtenemos los datos guardados en el registro indicado por el indice y convertimos esos datos a nuestra estructura
				Usuario* usuarioSeleccionado = (Usuario*)SendDlgItemMessage(hDialogoActual, LBX_USUARIOS, LB_GETITEMDATA, indice, NULL);

				SetDlgItemTextA(hDialogoActual, TXT_NOMUS, usuarioSeleccionado->Nombre.c_str());
				SetDlgItemTextA(hDialogoActual, TXT_CONTRAUS, usuarioSeleccionado->Contrasena.c_str());

				HBITMAP img = (HBITMAP)LoadImageA(GlobalhIdentificador, usuarioSeleccionado->RutaImagen, IMAGE_BITMAP, 64, 64, LR_LOADFROMFILE);
				HWND hPictureControl = GetDlgItem(hDialogoActual, PIC_IMAGEN);
				SendMessage(hPictureControl, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)img);
			}
			break;
			}
		}
		}
	}
	break;
	}
	return FALSE;
}

INT_PTR CALLBACK fnDlgInicioSesion
(
	HWND hDialogoActual, //referencia al dialogo que se esta siendo desplegado/llamado
	UINT uMensaje,			//mensaje o evento de interaccion en Windows
	WPARAM wParam,			//contienen informacion adicional del mensaje
	LPARAM lParam				//contienen informacion adicional del mensaje
)
{
	switch (uMensaje)
	{
	case WM_INITDIALOG:
	{
		SetDlgItemTextA(hDialogoActual, LBL_ERRORUSUARIO, "");
		SetDlgItemTextA(hDialogoActual, LBL_ERRORCONTRASENA, "");
	}
	break;
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
	
		break;
		case BTN_SALIR:
		{
			MostrarMensajeDeCierre();
		}
		break;
		case BTN_INICIOSESION:
		{

			//Obtenemos los textos desde las pantallas y los guardamos en arreglos de chars
			char nombreDeUsuario[50], contrasena[50];
			GetDlgItemTextA(hDialogoActual, TXT_USUARIO, nombreDeUsuario, 50);
			GetDlgItemTextA(hDialogoActual, TXT_CONTRASENA, contrasena, 50);

			//Convertimos los arreglos de chars a datos tipo string
			string nombreDeUsuarioStr(nombreDeUsuario);
			string contrasenaStr(contrasena);

			//Aqui empezamos la validacion de las credenciales ingresadas
			bool hayError = false;

			string msjErrorUsuario = "";
			string msjErrorContrasena = "";

			if (nombreDeUsuarioStr == "")
			{
				msjErrorUsuario = "El usuario es requerido";

				hayError = true;
			}

			if (nombreDeUsuarioStr.length() < 3)
			{
				msjErrorUsuario = "El usuario debe tener minimo 3 caracteres";
				hayError = true;
			}

			if (contrasenaStr == "")
			{
				msjErrorContrasena = "La contrasena es requerida";
				hayError = true;
			}

			if (hayError == true)
			{
				//Si los datos son invalidos, procedemos a mostrar los mensajes de error
				SetDlgItemTextA(hDialogoActual, LBL_ERRORUSUARIO, msjErrorUsuario.c_str());
				SetDlgItemTextA(hDialogoActual, LBL_ERRORCONTRASENA, msjErrorContrasena.c_str());
				return FALSE;
			}

			//Si los datos cumplen con las reglas de validacion, o son validos, entonces procedemos a checar si las credenciales
			//ingresadas coinciden con algun registro de la lista
			bool usuarioLogeado = false;

			Usuario* aux = INICIO_LISTA;
			while (aux != NULL)
			{
				if (nombreDeUsuarioStr == aux->Nombre && contrasenaStr == aux->Contrasena)
				{
					usuarioLogeado = true;
					UsuarioEnSesion = aux;

					HWND hDlg = CreateDialogW(GlobalhIdentificador, MAKEINTRESOURCE(IDD_PRINCIPAL), NULL, fnDlgPantallaPrincipal);

					ShowWindow(hDlg, SW_SHOW);
					DestroyWindow(hDialogoActual);
				}
				aux = aux->Siguiente;
			}

			//Si ningun registro hace match entonces mostrar un mensaje de error
			if (usuarioLogeado == false)
			{
				MessageBoxA(NULL, "Las credenciales ingresadas son invalidas", "Datos incorrectos", MB_ICONERROR);
			}
		}
		break;
		}
	}
	break;
	case WM_CLOSE:
	{
		MostrarMensajeDeCierre();
	}
	break;
	}

	return FALSE;
}

int WINAPI wWinMain
(
	//identificador de la aplicacion 
	// Sirve para que el SO identifique a nuestra app y para realizar ciertas funciones con ese identificador
	HINSTANCE hIdentificador, //200
	// Progrma que abrio la aplicacion actual - nosotros no lo usamos
	HINSTANCE hProgramaPrevio,
	// contiene los argumentos recibidos desde la linea de comandos - nosotros no lo usamos
	PWSTR pArgumentosLineaComandos,
	// Como se va a mostrar o desplegar la ventana - nosotros no lo usamos
	int nTipoMuestraDeVentana
)
{
	GlobalhIdentificador = hIdentificador;

	LeerUsuariosDesdeArchivo();

	IMGDEFAULT = (HBITMAP)LoadImageA(GlobalhIdentificador, "profile_default_2.bmp", IMAGE_BITMAP, 128, 128, LR_LOADFROMFILE);

	if (INICIO_LISTA == NULL)
	{
		Usuario* admin = new Usuario;
		admin->Nombre = "Ray";
		admin->Contrasena = "1234";
		admin->TipoUsuario = USUARIO_ADMIN;
		//admin->RutaImagen = new wchar_t[255];
		strcpy(admin->RutaImagen, "profile_default.bmp");
		admin->Siguiente = NULL;
		INICIO_LISTA = admin;
	}

	HWND hDlg = CreateDialogW(
		//Identificador de la aplicacion
		hIdentificador,
		//ID de la plantilla de dialogo que vamos a usar _CRT_SECURE_NO_WARNINGS_
		MAKEINTRESOURCE(DLG_INICIOSESION),
		// Referencia a la ventana padre
		NULL,
		// Funcion que define el comportamiento del dialogo a crear
		fnDlgInicioSesion
	);

	ShowWindow(hDlg, SW_SHOW);

	//Message loop  - Ciclo de mensaje

	//escuchamos cualquier mensaje en el message loop
	MSG msg = { };

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}


/*
*
* RUTINA PARA RECORRER LISTA DE USUARIOS
*
Usuario* aux = INICIO_LISTA;
while (aux != NULL)
{

	aux = aux->Siguiente;
}

int respuesta = MessageBoxA(
				NULL,
				"Deseas iniciar sesion?",
				"Iniciando sesion...",
				MB_OKCANCEL | MB_ICONQUESTION
			);

			if (respuesta == IDOK) //si el usuario le dio click al boton de aceptar en el Messagebox
			{
				MessageBoxA(
					NULL,
					"Has iniciado sesion",
					"Sesion iniciada",
					MB_OK | MB_ICONEXCLAMATION
				);
			}
			else if (respuesta == IDCANCEL)
			{
				MessageBoxA(
					NULL,
					"Has cancelado el inicio de sesion",
					"Sesion cancelada",
					MB_OK | MB_ICONSTOP
				);
			}
*/
