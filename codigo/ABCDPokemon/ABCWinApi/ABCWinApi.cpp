#include <windows.h>
#include <string>
#include "resource.h"
#include <fstream>

using namespace std;

wchar_t* rutaDeImageEnDisco = new wchar_t[255];
HINSTANCE GLOBAL_hInstancia;
struct Pkmn
{
  string Nombre;
  int Numero;
  int Ataque;
  int Defensa;
  int Velocidad;
  wchar_t* rutaDeImagen;
  Pkmn* Siguiente;

  string GenerarEnFormatoCSV()
  {
    string str;
    str.append(Nombre);
    str.append(",");
    str.append(to_string(Numero));
    str.append(",");
    str.append(to_string(Ataque));
    str.append(",");
    str.append(to_string(Defensa));
    str.append(",");
    str.append(to_string(Velocidad));
    return str;
  }
};

Pkmn* Inicio;
Pkmn* pkmnAEditar;

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

    case BTN_CSV:
    {
      fstream archivo;
      archivo.open("pkmn.csv", ios::out);
      Pkmn* aux = Inicio;
      while (aux != NULL)
      {
        archivo << aux->GenerarEnFormatoCSV() << "\n";
        //archivo << aux->Nombre << "," << aux->Numero << "," << aux->Ataque << "," << aux->Defensa << "," << aux->Velocidad << "\n";
        aux = aux->Siguiente;
      }
      archivo.close();

    }
    break;
    case BTN_CARGARFOTO:
    {

      OPENFILENAME ofn;
      ZeroMemory(&ofn, sizeof(OPENFILENAME));

      ofn.hwndOwner = hDialogoActual; // definimos el dialogo padre
      ofn.lStructSize = sizeof(OPENFILENAME); // tamano de la estructura
      ofn.lpstrFile = rutaDeImageEnDisco; // aqui se guarda el nombre/ruta de la imagen
      ofn.nMaxFile = 255; // longitud del nombre del archivo
      ofn.lpstrDefExt = L"bmp"; //extension de archivos de imagen a manejar
      ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_NOCHANGEDIR;
      ofn.lpstrFilter = L"Imagenes BMP\0*.bmp";

      if (GetOpenFileName(&ofn))
      {
        //cargo la imagen de mapa de bits en memoria
        HBITMAP bitmap = (HBITMAP)LoadImage(GLOBAL_hInstancia, rutaDeImageEnDisco, IMAGE_BITMAP, 256, 256, LR_LOADFROMFILE);
        //obtengo la referencia al picture control
        HWND hPictureControl = GetDlgItem(hDialogoActual, PIC_FOTO);
        //Enviar la imagen al control
        SendMessage(hPictureControl, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bitmap);

        //u.image = rutaDeImageEnDisco;
      }

    }
    break;
    case BTN_PRUEBAS:
    {
      HWND hListbox = GetDlgItem(hDialogoActual, LBX_POKEDEX);
      SendMessageA(hListbox, LB_ADDSTRING, 0, (LPARAM)"Prueba");
    }
    break;
    case BTN_ELIMINAR:
    {
      int indice = SendDlgItemMessage(hDialogoActual, LBX_POKEDEX, LB_GETCURSEL, NULL, NULL);
      
      Pkmn* pkmnAEliminar =
        (Pkmn*)SendDlgItemMessage(
          hDialogoActual, //dialogo actual donde se encuentra el listbox
          LBX_POKEDEX,    //ID del listbox
          LB_GETITEMDATA, //Mensaje que indica que vamos a obtener los datos guardados en el registro indicado por el indice
          indice,         //El indice de elemento del listado
          NULL);

      //Para eliminar un nodo de la lista hay 3 escenarios:
      //Cuando el nodo esta al principio, en medio o al final de la lista

      if (pkmnAEliminar == Inicio)
      {
        Inicio = Inicio->Siguiente;
        delete pkmnAEliminar;
      }
      else if (pkmnAEliminar->Siguiente == NULL)
      {
        Pkmn* aux = Inicio;
        while (aux->Siguiente != pkmnAEliminar)
        {
          aux = aux->Siguiente;
        }
        aux->Siguiente = NULL;
        delete pkmnAEliminar;
      }
      else {
        Pkmn* aux = Inicio;
        while (aux->Siguiente != pkmnAEliminar)
        {
          aux = aux->Siguiente;
        }
        aux->Siguiente = pkmnAEliminar->Siguiente;
        delete pkmnAEliminar;
      }

      SendDlgItemMessage(hDialogoActual, LBX_POKEDEX, LB_DELETESTRING, indice, 0);
    }
    break;  
    case BTN_EDITAR:
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

      pkmnAEditar->Nombre = Nombre;
      pkmnAEditar->Numero = Numero;
      pkmnAEditar->Ataque = Ataque;
      pkmnAEditar->Defensa = Defensa;
      pkmnAEditar->Velocidad = Velocidad;

      //Al final limpiamos los campos de texto
      LimpiarDatos(hDialogoActual);


      //Aqui eliminamos la cadena desactualizada del Listbox
      int indice = SendDlgItemMessage(hDialogoActual, LBX_POKEDEX, LB_GETCURSEL, NULL, NULL);
      SendDlgItemMessage(hDialogoActual, LBX_POKEDEX, LB_DELETESTRING, indice, 0);


      HWND hListbox = GetDlgItem(hDialogoActual, LBX_POKEDEX);

      string texto = "#" + to_string(Numero) + " - " + Nombre;
      indice = SendMessageA(hListbox, LB_ADDSTRING, 0, (LPARAM)texto.c_str());
      SendMessage(hListbox, LB_SETITEMDATA, indice, (LPARAM)pkmnAEditar);
      
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

      pkmn->rutaDeImagen = new wchar_t[255];

      for (int i = 0; i < 255; i++)
      {
        pkmn->rutaDeImagen[i] = rutaDeImageEnDisco[i];
      }



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
        pkmnAEditar =
          (Pkmn*)SendDlgItemMessage(
            hDialogoActual, //dialogo actual donde se encuentra el listbox
            LBX_POKEDEX,    //ID del listbox
            LB_GETITEMDATA, //Mensaje que indica que vamos a obtener los datos guardados en el registro indicado por el indice
            indice,         //El indice de elemento del listado
            NULL);

        string texto = "El pokemon seleccionado fue el #" + to_string(pkmnAEditar->Numero) + " - " + pkmnAEditar->Nombre;
        MessageBoxA(hDialogoActual, texto.c_str(), "Prueba", MB_OK);

        SetDlgItemTextA(hDialogoActual, TXT_NOMBRE, pkmnAEditar->Nombre.c_str());
        SetDlgItemTextA(hDialogoActual, TXT_NUMERO, to_string(pkmnAEditar->Numero).c_str());
        SetDlgItemTextA(hDialogoActual, TXT_ATAQUE, to_string(pkmnAEditar->Ataque).c_str());
        SetDlgItemTextA(hDialogoActual, TXT_DEFENSA, to_string(pkmnAEditar->Defensa).c_str());
        SetDlgItemTextA(hDialogoActual, TXT_VELOCIDAD, to_string(pkmnAEditar->Velocidad).c_str());

        HBITMAP bitmap = (HBITMAP)LoadImage(GLOBAL_hInstancia, pkmnAEditar->rutaDeImagen, IMAGE_BITMAP, 256, 256, LR_LOADFROMFILE);
        HWND hPictureControl = GetDlgItem(hDialogoActual, PIC_FOTO);
        SendMessage(hPictureControl, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bitmap);

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
  GLOBAL_hInstancia = hIdentificadorApp;
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