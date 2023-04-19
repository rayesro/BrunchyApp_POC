#include <windows.h>
#include "resource.h"	

//HWND - Handler Window - Manejador de ventana - Referencia a la ventana

INT_PTR CALLBACK fnDialogoPrincipal(
	HWND hDialogoPadre,//contiene la referencia del dialogo 
	UINT uMensaje, //Identificador del mensaje o evento generado en un dialogo
	WPARAM wParam, //datos o informacion adicional del evento o mensaje generado (esta informacion depende del tipo de evento)
	LPARAM lParam	 //datos o informacion adicional del evento o mensaje generado (esta informacion depende del tipo de evento)
)
{
	switch (uMensaje)
	{
	case WM_INITDIALOG://Initialize dialog  - inicializar dialogo
	{
		MessageBox(NULL, L"Se esta cargando la informacion", L"Preparando dialogo", MB_ICONEXCLAMATION | MB_OK);
		//Abrir un archivo y cargar el listado de usuarios
		//Otras acciones para inicializar los componentes de nuestro dialogo
	}
	break;
	case WM_CLOSE://Window Message - Close
	{
		MessageBox(NULL, L"No me voy a cerrar", L"Te engañe!!!", MB_ICONEXCLAMATION | MB_OK);
		//Guardar los datos en archivo
		//Liberar la memoria reservada
		//Podemos despedir al usuario
	}
	break;
	default:
		break;
	}

	return 0;
}

INT_PTR CALLBACK fnDialogoPerfilUsuario(
	HWND hDialogoPadre,//contiene la referencia del dialogo 
	UINT uMensaje, //Identificador del mensaje o evento generado en un dialogo
	WPARAM wParam, //datos o informacion adicional del evento o mensaje generado (esta informacion depende del tipo de evento)
	LPARAM lParam	 //datos o informacion adicional del evento o mensaje generado (esta informacion depende del tipo de evento)
)
{
	
	return 0;
}


int WINAPI wWinMain(
	HINSTANCE hInstance, //identificador de nuestra aplicacion
	HINSTANCE prevInstance, //Indentificador de una aplicacion previa - lo podemos ignorar
	PWSTR pCmdLine, // los argumentos de la linea de comandos
	int nCmdShow // sirve para indicar como se va a desplegar la pantalla
)
{
	//

	HWND hDlgPrincipal = CreateDialogW(
		hInstance, //identificador de nuestra aplicacion
		MAKEINTRESOURCE(DLG_PRINCIPAL), //aqui le pasamos el recurso o dialogo a usar para mostrar,
		NULL,// referencia del manejador de la ventana padre
		fnDialogoPerfilUsuario //funcion que define el comportamiento del dialogo que se va a crear
	);

	ShowWindow(hDlgPrincipal, SW_SHOW);


	//Creamos un ciclo que mantenga la aplicacion corriendo
	//Message loop
	MSG msj = {};

	while (GetMessage(&msj, NULL, 0, 0))
	{
		TranslateMessage(&msj);
		DispatchMessage(&msj);
	}
	
	
	return 0;
}