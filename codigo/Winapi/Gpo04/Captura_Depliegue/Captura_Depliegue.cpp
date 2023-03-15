#include<Windows.h>
#include "resource.h"
#include <string>
using namespace std;

int contador = 0;
HINSTANCE GlobalhIdentificador;

enum TipoUsuario{ADMIN,CAJERO};

struct User
{
	string nom;
	string contra;
	int tipoUs;
	string tipoUsuario;
}usuarios[3];

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
			SetDlgItemTextA(
				hDialgoActual,
				LBL_ERRORUSUARIO,
				""
			);
			SetDlgItemTextA(
				hDialgoActual,
				LBL_ERRORCONTRASENA,
				"_._"
			);
		}
		break;
		case WM_COMMAND:
		{
			switch (LOWORD(wParam))
			{
			case BTN_PRUEBA:
			{
				//string s = "0";//aa // aaa ///aaaa
				//contador++;
				//for (int i = 0; i < contador; i++)
				//{
				//	s += to_string(i+1);
				//}
				//SetDlgItemTextA(
				//	hDialgoActual,
				//	LBL_ERRORCONTRASENA,
				//	s.c_str()
				//);
				//IDD_DIALOG1
				HWND hDlg = CreateDialogW(
					GlobalhIdentificador,
					MAKEINTRESOURCE(IDD_DIALOG1),
					NULL,
					fnDlgInicioSesion
				);

				ShowWindow(hDlg, SW_SHOW);
				DestroyWindow(hDialgoActual);
			}
			break;
			case BTN_SALIR:
			{
				int respuesta = MessageBoxA(
					NULL,
					"Estas seguro que quieres cerrar la aplicacion?",
					"Cerrando aplicacion...",
					MB_OKCANCEL | MB_ICONQUESTION
				);

				if (respuesta == IDOK) //si el usuario le dio click al boton de aceptar en el Messagebox
				{
					PostQuitMessage(0);
				}
			}
				break;
			case BTN_INICIOSESION:
			{
				SetDlgItemTextA(
					hDialgoActual,
					LBL_ERRORUSUARIO,
					""
				);
				char nombreDeUsuario[50], contrasena[50];

				GetDlgItemTextA(
					hDialgoActual,
					TXT_USUARIO,
					nombreDeUsuario,
					50
				);

				GetDlgItemTextA(
					hDialgoActual,
					TXT_CONTRASENA,
					contrasena,
					50
				);

				string nombreDeUsuarioStr(nombreDeUsuario);
				string contrasenaStr(contrasena);

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
					msjErrorUsuario = "El usuario debe tener minimo 3 caracters";
					hayError = true;
				}

				if (contrasenaStr == "")
				{
					msjErrorContrasena = "La contrasena es requerida";
					hayError = true;
				}

				if (hayError == true)
				{
					SetDlgItemTextA(
						hDialgoActual,
						LBL_ERRORUSUARIO,
						msjErrorUsuario.c_str()
					);
					SetDlgItemTextA(
						hDialgoActual,
						LBL_ERRORCONTRASENA,
						msjErrorContrasena.c_str()
					);
					return FALSE;
				}

				bool usuarioLogeado = false;

				for (int i = 0; i < 3; i++)
				{
					if (nombreDeUsuarioStr == usuarios[i].nom && contrasenaStr == usuarios[i].contra)
					{
						usuarioLogeado =  true;
						/*string mensaje = "El usuario es: " + nombreDeUsuarioStr + " puede iniciar sesion";
						if (usuarios[i].tipoUs == ADMIN)
							mensaje += " y es Administrador";
						else
							mensaje += " y es cajero";*/
						/*MessageBoxA(
							NULL,
							mensaje.c_str(),
							"Datos correctos",
							MB_OK
						);*/

						//IDD_DIALOG1
						HWND hDlg = CreateDialogW(
							GlobalhIdentificador,
							MAKEINTRESOURCE(IDD_DIALOG1),
							NULL,
							fnDlgInicioSesion
						);

						ShowWindow(hDlg, SW_SHOW);
						DestroyWindow(hDialgoActual);
					}
				}
				

				if (usuarioLogeado == false)
				{
					MessageBoxA(
						NULL,
						"Las credenciales ingresadas son invalidas",
						"Datos incorrectos",
						MB_ICONERROR
					);
				}



				
			}
					break;
			}
		}
		break;
		case WM_CLOSE:
		{
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

	User u1 = { "ray", "123", ADMIN};
	User u2 = { "mar", "456", CAJERO};
	User u3 = { "lui", "xyz", CAJERO };
	usuarios[0] = u1;
	usuarios[1] = u2;
	usuarios[2] = u3;

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