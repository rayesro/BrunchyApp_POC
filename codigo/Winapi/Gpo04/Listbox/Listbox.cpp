#include<Windows.h>
#include "resource.h"
#include <string>

#include <fstream>

using namespace std;

HINSTANCE GLOBALhIdentificador;

string ADMINUSER = "RAY";
string ADMINPASS = "123";

struct Pkmn
{
	string nombre;
	string descripcion;
	int numero;
};


Pkmn pokemones[10];
int CONTADOR_PKMN = 0;

INT_PTR CALLBACK fnDlgPokedex(HWND hDialogoActual,UINT uMensaje,WPARAM wParam,LPARAM lParam);

INT_PTR CALLBACK fnDlgVentana2
(
	HWND hDialogoActual, //referencia al dialogo que se esta siendo desplegado/llamado
	UINT uMensaje,			//mensaje o evento de interaccion en Windows
	WPARAM wParam,			//contienen informacion adicional del mensaje
	LPARAM lParam				//contienen informacion adicional del mensaje
)
{
	switch (uMensaje)
	{
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case IDCANCEL: {
			HWND hDlg = CreateDialogW(
				GLOBALhIdentificador,
				MAKEINTRESOURCE(DLG_POKEDEX),
				NULL,
				fnDlgPokedex);

			ShowWindow(hDlg, SW_SHOW);
			DestroyWindow(hDialogoActual);
		}
		break;
		}
	}
	break;
	case WM_CLOSE: {
		PostQuitMessage(0);
	}
		break;
	}
	return FALSE;
}

INT_PTR CALLBACK fnDlgVentana3
(
	HWND hDialogoActual, //referencia al dialogo que se esta siendo desplegado/llamado
	UINT uMensaje,			//mensaje o evento de interaccion en Windows
	WPARAM wParam,			//contienen informacion adicional del mensaje
	LPARAM lParam				//contienen informacion adicional del mensaje
)
{
	switch (uMensaje)
	{
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case IDOK: {
			HWND hDlg = CreateDialogW(
				GLOBALhIdentificador,
				MAKEINTRESOURCE(DLG_POKEDEX),
				NULL,
				fnDlgPokedex);

			ShowWindow(hDlg, SW_SHOW);
			DestroyWindow(hDialogoActual);
		}
			break;
		}
	}
	break;
	case WM_CLOSE: {
		PostQuitMessage(0);
	}
	break;
	}
	return FALSE;
}

INT_PTR CALLBACK fnDlgPokedex
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
		HWND hListbox = GetDlgItem(hDialogoActual, LBX_POKEDEX);
		for (int i = 0; i < CONTADOR_PKMN; i++)
		{
			string formato = "#" + to_string(pokemones[i].numero) + " - " + pokemones[i].nombre;
			int indice = SendMessageA(hListbox, LB_ADDSTRING, 0, (LPARAM)formato.c_str());
			SendMessage(hListbox,LB_SETITEMDATA, indice,(LPARAM)&pokemones[i]);
		}

		HMENU menu = LoadMenu(GLOBALhIdentificador,MAKEINTRESOURCE(IDR_MENU1));
		SetMenu(hDialogoActual, menu);

	}
	break;
	case WM_CLOSE:
	{
		int respuesta = MessageBoxA(hDialogoActual, "Esta seguro que quieres cerrar la aplicacion?", "Cerrando app...", MB_OKCANCEL | MB_ICONASTERISK);
		if (respuesta == IDOK)
		{
			fstream archivo;
			archivo.open("pokemon.bin", ios::out | ios::binary);

			//aux = INICIO;
			//while (aux != NULL)
			//{
			//	//pondriamos la logica para guardar en un archivo 
			// archivo.write((char*)aux, sizeof(Pkmn));
			//	aux = aux->sig;
			//}

			for (int i = 0; i < CONTADOR_PKMN; i++)
			{
				//pondriamos la logica para guardar en un archivo 
				archivo.write((char*)&pokemones[i], sizeof(Pkmn));
			}
			archivo.close();

			PostQuitMessage(0);//esta funcion termina la aplicacion
		}
	}
	break;
	case WM_COMMAND: 
	{
		switch (LOWORD(wParam))
		{
		case BTN_VENTANA2:
		{
			HWND hDlg = CreateDialogW(
				GLOBALhIdentificador,
				MAKEINTRESOURCE(DLG_VENTANA2),
				NULL,
				fnDlgVentana2);

			ShowWindow(hDlg, SW_SHOW);
			DestroyWindow(hDialogoActual);

		}break;
		case BTN_VENTANA3:
		case ID_GUARDARPOKEMON:
		{
			HWND hDlg = CreateDialogW(
				GLOBALhIdentificador,
				MAKEINTRESOURCE(DLG_VENTANA3),
				NULL,
				fnDlgVentana3);

			ShowWindow(hDlg, SW_SHOW);
			DestroyWindow(hDialogoActual);
		}break;
		case BTN_PRUEBAS:
		{
			HWND hListbox = GetDlgItem(hDialogoActual, LBX_POKEDEX);
			SendMessageA(hListbox, LB_ADDSTRING, 0, (LPARAM)"#25 - Pikachu");
		}
		break;
		case BTN_LIMPIARDATOS:
		{
			SetDlgItemTextA(hDialogoActual, TXT_NOMBRE, "");
			SetDlgItemTextA(hDialogoActual, TXT_NUMERO, "");
		
		}
		break;
		case BTN_GUARDARPKMN:
		{
			char nombre[50],  num[5];

			GetDlgItemTextA(hDialogoActual, TXT_NOMBRE, nombre, 50);
			GetDlgItemTextA(hDialogoActual, TXT_NUMERO, num, 5);

			pokemones[CONTADOR_PKMN].nombre = nombre;
			pokemones[CONTADOR_PKMN].numero = atoi(num); // atoi = ascii to integer
			if (pokemones[CONTADOR_PKMN].numero > 0 && pokemones[CONTADOR_PKMN].numero < 151)
			{
				pokemones[CONTADOR_PKMN].descripcion = pokemones[CONTADOR_PKMN].nombre + "- 1 GEN";
			}
			else
			{
				pokemones[CONTADOR_PKMN].descripcion = pokemones[CONTADOR_PKMN].nombre + "- 2 GEN";
			}

			string pkmnRestantes = to_string(10 - CONTADOR_PKMN);

			string titulo = "Pokedex.... quedan " + pkmnRestantes + " espacios";
			SetDlgItemTextA(hDialogoActual, LBL_POKEDEX, titulo.c_str());

			//Para poner datos en el listbox, tenemos que seguir los siguientes pasos...
			//1-Obtener la referencia al componente de Listbox, en este caso, al ID LBX_POKEDEX
			HWND hListbox = GetDlgItem(hDialogoActual, LBX_POKEDEX);

			//2-Mandar un mensaje para agregar una cadena de texto al listbox usando su HWND
			//En este caso, mandamos como texto la concatenacion de "#<Numero> - <Nombre>"
			string formato = "#" + to_string(pokemones[CONTADOR_PKMN].numero) + " - " + pokemones[CONTADOR_PKMN].nombre;

			//3-Guardar el indice que regresa la funcion SendMessageA
			int indice = SendMessageA(hListbox, LB_ADDSTRING, 0, (LPARAM)formato.c_str());

			//4-Usar el indice para establecer o guardar datos dentro del listbox
			SendMessage(
				hListbox,				//la referencia al listbox ya que a ese listbox vamos a mandar el mensaje
				LB_SETITEMDATA, //Establece o guarda datos en un registro del listbox
				indice,					//indice del listbox donde va a guardar los datos
				(LPARAM)&pokemones[CONTADOR_PKMN]		//los datos a guardar
			);

			SetDlgItemTextA(hDialogoActual, TXT_NOMBRE, "");
			SetDlgItemTextA(hDialogoActual, TXT_NUMERO, "");
			CONTADOR_PKMN++;
		}
		break;
		//5-Agregamos el codigo para manejar el evento cuando le demos click a cualquiera de los 
		//registros del listbox
		case LBX_POKEDEX:
		{
			switch (HIWORD(wParam))
			{
			//LBN_SELCHANGE = Selection Change = cambio en la seleccion de registros del listbox
			case LBN_SELCHANGE:
			{
				//6-Obtener el indice del registro del listbox al que le dimos click
				int indice = SendDlgItemMessage(hDialogoActual, LBX_POKEDEX, LB_GETCURSEL, NULL, NULL);
				//7-Obtenemos los datos guardados en el registro indicado por el indice y convertimos
			  //esos datos a nuestra estructura tipo pkmn

				Pkmn* pkmn = (Pkmn*)SendDlgItemMessage(hDialogoActual, LBX_POKEDEX, LB_GETITEMDATA, indice, NULL);

				//SendDlgItemMessage(
				//	hDialogoActual, //dialogo actual donde se encuentra el listbox
				//	LBX_POKEDEX,    //ID del listbox
				//	LB_GETITEMDATA, //Mensaje que indica que vamos a obtener los datos guardados en el registro indicado por el indice
				//	indice,         //El indice de elemento del listado
				//	NULL);

				//string texto = "El pokemon seleccionado fue " + pkmn->nombre + "#"+ to_string(pkmn->numero);
				//MessageBoxA(hDialogoActual, texto.c_str(), "pkmn seleccionado", MB_OK);
				SetDlgItemTextA(hDialogoActual, TXT_NOMBRE, pkmn->nombre.c_str());
				SetDlgItemTextA(hDialogoActual, TXT_NUMERO, to_string(pkmn->numero).c_str());
				SetDlgItemTextA(hDialogoActual, LBL_DESCRIPCION, pkmn->descripcion.c_str());
			}
			break;
			}
		}
		break;
		}
	
	
	}
	break;
	}
	return FALSE;
}


int WINAPI wWinMain
(
	//identificador de la aplicacion 
	// Sirve para que el SO identifique a nuestra app y para realizar ciertasfunciones con ese identificador
	HINSTANCE hIdentificador, 
	// Progrma que abrio la aplicacion actual - nosotros no lo usamos
	HINSTANCE hProgramaPrevio,
	// contiene los argumentos recibidos desde la linea de comandos - nosotros no lo usamos
	PWSTR pArgumentosLineaComandos,
	// Como se va a mostrar o desplegar la ventana - nosotros no lo usamos
	int nTipoMuestraDeVentana
)
{
	//leer los archivos si es que existen
	fstream archivo;
	archivo.open("pokemon.bin", ios::in | ios::binary | ios::ate); //at the end
	if (archivo.is_open()) //is_open valida que el archivo fue abierto con exito
	{

		int tamanioDeArchivoEnBytes = archivo.tellg(); //tellg (tell get pointer/cursor) -> damos la posicion del cursor
		int totalPkmns = tamanioDeArchivoEnBytes / sizeof(Pkmn);
		
		for (int i = 0; i < totalPkmns; i++)
		{
			Pkmn* temporal = new Pkmn;
			//seekg posiciona el cursor de lectura en X posicion
			archivo.seekg(i * sizeof(Pkmn));
			archivo.read((char*)temporal, sizeof(Pkmn));
			pokemones[i] = *temporal;
			CONTADOR_PKMN++;
		}
	}
	archivo.close();

	GLOBALhIdentificador = hIdentificador;
	HWND hDlg = CreateDialogW(
		//Identificador de la aplicacion
		hIdentificador,
		//ID de la plantilla de dialogo que vamos a usar
		MAKEINTRESOURCE(DLG_POKEDEX),
		// Referencia a la ventana padre
		NULL,
		// Funcion que define el comportamiento del dialogo a crear
		fnDlgPokedex
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