#include <Windows.h>
#include "resource.h"
#include <string>
#include <fstream>

using namespace std;

int contador = 0;
HINSTANCE GlobalhIdentificador;

#define USUARIO_ADMIN  1 
#define USUARIO_CAJERO 2

struct Usuario{
	string Nombre;
	string Contrasena;
	int TipoUsuario;
	Usuario* Siguiente;

	wchar_t* RutaImagen;
};

Usuario* INICIO_LISTA = NULL;
Usuario* UsuarioEnSesion = NULL;

void GuardarUsuariosEnArchivo()
{
	fstream archivo;
	archivo.open("usuarios.bin", ios::binary | ios::out);

	Usuario* aux = INICIO_LISTA;
	while (aux != NULL)
	{
		archivo.write((char*)aux,sizeof(Usuario));
		aux = aux->Siguiente;
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
	int respuesta = MessageBoxA(NULL,"Estas seguro que quieres cerrar la aplicacion?","Terminando aplicacion...",MB_OKCANCEL | MB_ICONQUESTION);
	if (respuesta == IDOK) //si el usuario le dio click al boton de aceptar en el Messagebox
	{
		GuardarUsuariosEnArchivo();
		PostQuitMessage(0);
	}
}

INT_PTR CALLBACK fnDlgPantallaPrincipal(HWND hDialgoActual, UINT uMensaje, WPARAM wParam, LPARAM lParam)
{
	switch (uMensaje)
	{
	case WM_INITDIALOG:
	{
		SetDlgItemTextA(hDialgoActual, LBL_NOMBREUSUARIO, UsuarioEnSesion->Nombre.c_str());

		//1-Obtener la referencia al componente del Listbox, en este caso, al ID LBX_USUARIOS
		HWND hListbox = GetDlgItem(hDialgoActual, LBX_USUARIOS);

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

			if (UsuarioEnSesion->TipoUsuario == USUARIO_ADMIN)
			{
				HMENU menu = LoadMenu(GlobalhIdentificador, MAKEINTRESOURCE(IDR_MENU1));
				SetMenu(hDialgoActual, menu);
			}
			else
			{
				HMENU menu = LoadMenu(GlobalhIdentificador, MAKEINTRESOURCE(IDR_MENU2));
				SetMenu(hDialgoActual, menu);
			}


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
			case BTN_NUEVO:
			{
				//obtenemos los datos de la pantalla
				char nombreDeUsuario[50], contrasena[50];
				GetDlgItemTextA(hDialgoActual, TXT_NOMUS, nombreDeUsuario, 50);
				GetDlgItemTextA(hDialgoActual, TXT_CONTRAUS, contrasena, 50);

				//Convertimos los arreglos de chars a datos tipo string
				string nombreDeUsuarioStr(nombreDeUsuario);
				string contrasenaStr(contrasena);

				//craemos un usuario y le asignamos los datos de la pantalla
				Usuario* nuevoUsuario = new Usuario;
				nuevoUsuario->Nombre = nombreDeUsuarioStr;
				nuevoUsuario->Contrasena = contrasenaStr;
				nuevoUsuario->TipoUsuario = USUARIO_CAJERO;
				nuevoUsuario->RutaImagen = new wchar_t[255];//reservar memoria para la ruta
				nuevoUsuario->Siguiente = NULL;

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
				HWND hListbox = GetDlgItem(hDialgoActual, LBX_USUARIOS);
				int indice = SendMessageA(hListbox, LB_ADDSTRING, 0, (LPARAM)nuevoUsuario->Nombre.c_str());
				SendMessage(hListbox,LB_SETITEMDATA,indice,(LPARAM)nuevoUsuario);
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
					int indice = SendDlgItemMessage(hDialgoActual, LBX_USUARIOS, LB_GETCURSEL, NULL, NULL);
					//7-Obtenemos los datos guardados en el registro indicado por el indice y convertimos esos datos a nuestra estructura
					Usuario* us = (Usuario*)SendDlgItemMessage(hDialgoActual,LBX_USUARIOS,LB_GETITEMDATA,indice,NULL);

					SetDlgItemTextA(hDialgoActual, TXT_NOMUS, us->Nombre.c_str());
					SetDlgItemTextA(hDialgoActual, TXT_CONTRAUS, us->Contrasena.c_str());
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
	HWND hDialgoActual, //referencia al dialogo que se esta siendo desplegado/llamado
	UINT uMensaje,			//mensaje o evento de interaccion en Windows
	WPARAM wParam,			//contienen informacion adicional del mensaje
	LPARAM lParam				//contienen informacion adicional del mensaje
)
{
	switch (uMensaje)
	{
		case WM_INITDIALOG:
		{
			SetDlgItemTextA(hDialgoActual,LBL_ERRORUSUARIO,"");
			SetDlgItemTextA(hDialgoActual,LBL_ERRORCONTRASENA,"");
		}
		break;
		case WM_COMMAND:
		{
			switch (LOWORD(wParam))
			{
			case BTN_SALIR:
			{
				MostrarMensajeDeCierre();
			}
			break;
			case BTN_INICIOSESION:
			{

				//Obtenemos los textos desde las pantallas y los guardamos en arreglos de chars
				char nombreDeUsuario[50], contrasena[50];
				GetDlgItemTextA(hDialgoActual,TXT_USUARIO,nombreDeUsuario,50);
				GetDlgItemTextA(hDialgoActual,TXT_CONTRASENA,contrasena,50);

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

				if (nombreDeUsuarioStr.length() < 3 )
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
					SetDlgItemTextA(hDialgoActual,LBL_ERRORUSUARIO,msjErrorUsuario.c_str());
					SetDlgItemTextA(hDialgoActual,LBL_ERRORCONTRASENA,msjErrorContrasena.c_str());
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

						HWND hDlg = CreateDialogW(GlobalhIdentificador,MAKEINTRESOURCE(IDD_PRINCIPAL),NULL, fnDlgPantallaPrincipal);

						ShowWindow(hDlg, SW_SHOW);
						DestroyWindow(hDialgoActual);
					}
					aux = aux->Siguiente;
				}

				//Si ningun registro hace match entonces mostrar un mensaje de error
				if (usuarioLogeado == false)
				{
					MessageBoxA(NULL,"Las credenciales ingresadas son invalidas","Datos incorrectos",MB_ICONERROR);
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

	if (INICIO_LISTA == NULL)
	{
		Usuario* admin = new Usuario;
		admin->Nombre = "Ray";
		admin->Contrasena= "1234";
		admin->TipoUsuario = USUARIO_ADMIN;
		admin->Siguiente = NULL;

		INICIO_LISTA = admin;
	}

	HWND hDlg = CreateDialogW(
		//Identificador de la aplicacion
		hIdentificador,
		//ID de la plantilla de dialogo que vamos a usar
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
