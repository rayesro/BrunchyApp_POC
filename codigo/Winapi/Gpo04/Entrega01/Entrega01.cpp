#include<Windows.h>
#include "resource.h"
#include <string>
using namespace std;


INT_PTR CALLBACK fnDlgInicioSesion
(
	HWND hDialogo, // identificador del dialogo que se esta ejecutando o mostrando
	UINT uMensaje, // identificador del mensaje o evento generado en el dialogo
	WPARAM wInfoExtra, //datos adicionales del evento o mensaje generado, depende del tipo de evento 
	LPARAM lInfoExtra  //datos adicionales del evento o mensaje generado, depende del tipo de evento 
)
{

	LPCSTR titulo = "Inicializando dialog";

	switch (uMensaje)
	{
	case WM_INITDIALOG:
	{
		//Abrir un archivo e inicializar la lista de usuario
		//inicializar otros componentes

		MessageBoxA(
			NULL,
			"Hola, LMADS!!!",
			titulo,
			MB_CANCELTRYCONTINUE | MB_ICONASTERISK
		);
	}
	break;

	case WM_CLOSE:
	{
		/**/
		//PostQuitMessage(0);

		titulo = "Me woa cerrar";
		MessageBoxA(
			NULL,
			"Hola, LMADS!!!",
			titulo,
			MB_CANCELTRYCONTINUE | MB_ICONASTERISK
		);
		PostQuitMessage(0);
	}
		break;
	}
	return 0;
}


INT_PTR CALLBACK fnDlgAltaUsuario(HWND hDialogo,UINT uMensaje,WPARAM wInfoExtra,LPARAM lInfoExtra)
{

	return 0;
}


int WINAPI wWinMain
(
	//identificador de la aplicacion 
	// Sirve para que el SO identifique a nuestra app y para realizar ciertasfunciones con ese identificador
	HINSTANCE hIdentificador, //200
	// Progrma que abrio la aplicacion actual - nosotros no lo usamos
	HINSTANCE hProgramaPrevio,
	// contiene los argumentos recibidos desde la linea de comandos - nosotros no lo usamos
	PWSTR pArgumentosLineaComandos,
	// Como se va a mostrar o desplegar la ventana - nosotros no lo usamos
	int nTipoMuestraDeVentana
)
{

	HWND hDlgInicioSesion = CreateDialogW(
		//Identificador de la aplicacion
		hIdentificador,
		//ID de la plantilla de dialogo que vamos a usar
		MAKEINTRESOURCE(DLG_INICIOSESION),
		// Referencia a la ventana padre
		NULL,
		// Funcion que define el comportamiento del dialogo a crear
		fnDlgInicioSesion
	);

	ShowWindow(hDlgInicioSesion, SW_SHOW);
	
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