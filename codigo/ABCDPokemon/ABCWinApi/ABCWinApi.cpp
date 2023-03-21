#include <windows.h>
#include <string>
#include "resource.h"
using namespace std;

struct Pkmn
{
  string Nombre;
  int Numero;
  int Ataque;
  int Defensa;
  int Velocidad;
  Pkmn* Siguiente;
};

Pkmn* Inicio;

Pkmn* CrearPokemon(string nombre, int num, int atk, int def, int vel)
{
  Pkmn* pkmn = new Pkmn;
  pkmn->Nombre = nombre;
  pkmn->Numero = num;
  pkmn->Ataque = atk;
  pkmn->Defensa = def;
  pkmn->Velocidad = vel;
  pkmn->Siguiente = NULL;
  return pkmn;
}

void InsertarPkmnAlFinalDeLaLista(Pkmn* pkmn)
{
  if (Inicio == NULL)
  {
    Inicio = pkmn;
  }
  else
  {
    Pkmn* aux = Inicio;
    while (aux->Siguiente != NULL)
    {
      aux = aux->Siguiente;
    }
    aux->Siguiente = pkmn;
  }
}

void LimpiarDatos(HWND hDlg)
{
  SetDlgItemTextA(hDlg, TXT_NOMBRE, "");
  SetDlgItemTextA(hDlg, TXT_NUMERO, "0");
  SetDlgItemTextA(hDlg, TXT_ATAQUE, "0");
  SetDlgItemTextA(hDlg, TXT_DEFENSA, "0");
  SetDlgItemTextA(hDlg, TXT_VELOCIDAD, "0");
}

INT_PTR CALLBACK fDlgCrearPkmn(HWND hDialogoActual, UINT uMensaje, WPARAM wParam, LPARAM lParam) 
{
  switch (uMensaje)
  {
  case WM_COMMAND:
  {
    switch (LOWORD(wParam))
    {
    case BTN_PRUEBAS:
    {
      HWND hListbox = GetDlgItem(hDialogoActual, LBX_POKEDEX);
      SendMessageA(hListbox, LB_ADDSTRING, 0, (LPARAM)"Prueba");
    }
    break;
    case BTN_CREAPKMN:
    {
      char nombre[30];
      char num[4];//124\0
      char  atk[4];
      char  def[4];
      char  vel[4];

      GetDlgItemTextA(hDialogoActual, TXT_NOMBRE, nombre, 30);
      GetDlgItemTextA(hDialogoActual, TXT_NUMERO, num, 4);
      GetDlgItemTextA(hDialogoActual, TXT_ATAQUE, atk, 4);
      GetDlgItemTextA(hDialogoActual, TXT_DEFENSA, def, 4);
      GetDlgItemTextA(hDialogoActual, TXT_VELOCIDAD, vel, 4);

      string Nombre(nombre);
      int Numero = atoi(num); // ascii to integer - para convertir de char[] a int
      int Ataque = atoi(atk);
      int Defensa = atoi(def);
      int Velocidad = atoi(vel);

      Pkmn* pkmn = CrearPokemon(Nombre, Numero, Ataque, Defensa, Velocidad);
      InsertarPkmnAlFinalDeLaLista(pkmn);

      //Para poner datos en el listbox, tenemos que seguir los siguientes pasos...

      //1-Obtener la referencia al componente de Listbox, en este caso, al ID LBX_POKEDEX
      HWND hListbox = GetDlgItem(hDialogoActual, LBX_POKEDEX);
      //2-Mandar un mensaje para agregar una cadena de texto al listbox usando su HWND
      //En este caso, mandamos como texto la concatenacion de "#<Numero> - <Nombre>"
      string texto = "#" + to_string(Numero) + " - " + Nombre;
      //3-Guardar el indice que regresa la funcion SendMessageA
      int indice = SendMessageA(hListbox, LB_ADDSTRING, 0, (LPARAM)texto.c_str());

      string IndiceStr = "El indice creado fue " + to_string(indice);
      MessageBoxA(hDialogoActual, IndiceStr.c_str(), "Prueba", MB_OK);

      //4-Usar el indice para establecer datos dentro del listbox
      SendMessage(
        hListbox, //la referencia al listbox ya que a ese listbox vamos a mandar el mensaje
        LB_SETITEMDATA, //Establece o guarda datos en un registro del listbox
        indice, //indice del listbox donde va a guardar los datos
        (LPARAM)pkmn //los datos a guardar
      );


      //Al final limpiamos los campos de texto
      LimpiarDatos(hDialogoActual);
    }
    break;
    case BTN_LIMPIARDATOS:
    {
      LimpiarDatos(hDialogoActual);
    }
    break;
    //5-Agregamos el codigo para manejar el evento cuando le demos click a cualquiera de los 
    //registros del listbox
    case LBX_POKEDEX:
    {
      switch (HIWORD(wParam))
      {
       //LBN_SELCHANGE = Selection Change = cambio en la seleccion de registros
      case LBN_SELCHANGE:
        //6-Obtener el indice del registro del listbox al que le dimos click
        int indice = SendDlgItemMessage(hDialogoActual, LBX_POKEDEX, LB_GETCURSEL, NULL, NULL);
        //7-Obtenemos los datos guardados en el registro indicado por el indice y convertimos
        //esos datos a nuestra estructura
        Pkmn* pkmn = 
          (Pkmn*)SendDlgItemMessage(
            hDialogoActual, //dialogo actual donde se encuentra el listbox
            LBX_POKEDEX,    //ID del listbox
            LB_GETITEMDATA, //Mensaje que indica que vamos a obtener los datos guardados en el registro indicado por el indice
            indice,         //El indice de elemento del listado
            NULL);

        string texto = "El pokemon seleccionado fue el #" + to_string(pkmn->Numero) + " - " + pkmn->Nombre;
        MessageBoxA(hDialogoActual, texto.c_str(), "Prueba", MB_OK);

        SetDlgItemTextA(hDialogoActual, TXT_NOMBRE, pkmn->Nombre.c_str());
        SetDlgItemTextA(hDialogoActual, TXT_NUMERO, to_string(pkmn->Numero).c_str());
        SetDlgItemTextA(hDialogoActual, TXT_ATAQUE, to_string(pkmn->Ataque).c_str());
        SetDlgItemTextA(hDialogoActual, TXT_DEFENSA, to_string(pkmn->Defensa).c_str());
        SetDlgItemTextA(hDialogoActual, TXT_VELOCIDAD, to_string(pkmn->Velocidad).c_str());

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



int WINAPI wWinMain(HINSTANCE hIdentificadorApp, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
  
  HWND hDlg = CreateDialogW(
    hIdentificadorApp,
    MAKEINTRESOURCE(DLG_CREARPKMN),
    NULL,
    fDlgCrearPkmn);

  ShowWindow(hDlg, SW_SHOW);
 
  // Run the message loop.

  MSG msg = { };
  while (GetMessage(&msg, NULL, 0, 0))
  {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  return 0;
}