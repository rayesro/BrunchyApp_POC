#include <windows.h>
#include <string>
#include "resource.h"

using namespace std;
HINSTANCE IdentificadorAppGlobal;

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
		SetDlgItemTextA(hDialgoActual, LBL_ERR_USUARIO, "");
		SetDlgItemTextA(hDialgoActual, LBL_ERR_CONTRASENA, "");
	}
		break;
	case WM_COMMAND: 
	{
		switch (LOWORD(wParam))
		{
		case BTN_INICIARSESION:
		{
			SetDlgItemTextA(hDialgoActual, LBL_ERR_USUARIO, "");
			SetDlgItemTextA(hDialgoActual, LBL_ERR_CONTRASENA, "");


			char usuarioChar[50], contrasenaChar[50];
			GetDlgItemTextA(hDialgoActual,TXT_USUARIO,usuarioChar,50);
			GetDlgItemTextA(hDialgoActual, TXT_CONTRASENA, contrasenaChar, 50);

			bool esUsuarioValido = true;
			string usuario(usuarioChar);
			string contrasena(contrasenaChar);

			string errorMensajeUsuario, errorMensajeContrasena;

			if (usuario.length() < 5 || usuario.length() > 20)
			{
				esUsuarioValido = false;
				errorMensajeUsuario = "El nombre del usuario debe tener entre 5 y 20 caracteres.";
			}
			
			for (int i = 0; i < usuario.length(); i++)
			{
				if (isalnum(usuario[i]) == false)
				{
					esUsuarioValido = false;
					errorMensajeUsuario = "El nombre del usuario solo puede contener caracteres alfanumericos.";
					break;
				}
			}
		
		

			string caracteresEspeciales = "!\"#$%&/()=?¡@_.:,;][*¨+´}{¿'¡?°|¬'`^~-";
			bool contrasenaTieneUnaLetra = false;
			bool contrasenaTieneUnNumero = false;
			bool contrasenaTieneUnCaracterEspecial = false;

			for (int i = 0; i < contrasena.length(); i++)
			{
				if (isalpha(contrasena[i]) != 0)
					contrasenaTieneUnaLetra = true;
				if (isdigit(contrasena[i]) != 0)
					contrasenaTieneUnNumero = true;
			}
			for (int i = 0; i < contrasena.length(); i++)
			{
				int dato = caracteresEspeciales.find(contrasena[i]);
				if ( dato > 0)
				{
					contrasenaTieneUnCaracterEspecial = true;
				}
			}

			if (contrasenaTieneUnaLetra == false)
			{
				errorMensajeContrasena = "La contrasena debe tener al menos una letra.";
			}
			else if (contrasenaTieneUnNumero == false)
			{
				errorMensajeContrasena = "La contrasena debe tener al menos un numero.";
			}else if (contrasenaTieneUnCaracterEspecial == false)
			{
				errorMensajeContrasena = "La contrasena debe tener al menos un caracter especial.";
			}


			if (contrasena.length() < 3 || contrasena.length() > 10)
			{
				esUsuarioValido = false;
				errorMensajeContrasena = "La contrasena debe tener entre 3 y 10 caracteres.";
			}



			if (esUsuarioValido == false)
			{
				//LBL_ERR_USUARIO
				SetDlgItemTextA(hDialgoActual, LBL_ERR_USUARIO, errorMensajeUsuario.c_str());
				SetDlgItemTextA(hDialgoActual, LBL_ERR_CONTRASENA, errorMensajeContrasena.c_str());
				return FALSE;
			}



		}
			break;
		}
	}
		break;
	}


	return FALSE;
}


int WINAPI wWinMain(
	HINSTANCE hIdentificador,     // Identificador de la aplicacion 
	HINSTANCE hPrevInstance, // Identificador de la aplicacion previa
	PWSTR pCmdLine,					 // argumentos de la linea de comandos
	int nCmdShow)						 // un valor que indica como se va a desplegar la pantalla
{
	IdentificadorAppGlobal = hIdentificador;

	HWND hDlgInicioSesion = CreateDialogW(
		hIdentificador,										//Identificador de la aplicacion 
		MAKEINTRESOURCE(DLG_INICIOSESION), //Id del dialogo
		NULL,															// HWND de Referencia a la ventana padre
		fnDlgInicioSesion
	);

	ShowWindow(hDlgInicioSesion, SW_SHOW);


	// Run the message loop.
	MSG msg = { };
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg); // traduce los eventos del teclado
		DispatchMessage(&msg);			 // despacha los mensajes a los callback de los dialogos
	}

	return 0;
}

