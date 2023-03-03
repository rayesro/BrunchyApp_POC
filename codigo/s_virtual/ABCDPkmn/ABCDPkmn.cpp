// ABCPkmn.cpp : This file contains the 'main' function. Program execution begins and ends there.
//scope ==> alcance

#include <iostream>
#include <fstream>
//#include "PkmnLib.h"

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

/*Hacer una funcion que cree y regrese un pokemon
y lo va a llenar con los datos de entrada o parametros
Nombre
Numero
Ataque
Defensa
Velocidad
*/


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

//
void ImprimirListaEnConsola()
{
  Pkmn* aux = Inicio;
  if (aux == NULL)
  {
    cout << "LA lista esta vacia\n";
    return;
  }
  while (aux != NULL)
  {
    cout << "Nombre:" << aux->Nombre << endl;
    cout << "Numero:" << aux->Numero << endl << endl;
    aux = aux->Siguiente;
  }
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


Pkmn* BuscarPkmn(string nombreAbuscar)
{
  Pkmn* pkmnABuscar = NULL;
  Pkmn* aux = Inicio;
  while (aux != NULL)
  {
    if (nombreAbuscar == aux->Nombre)
    {
      pkmnABuscar = aux;
      break;
    }
    aux = aux->Siguiente;
  }

  return pkmnABuscar;
}

void EditarPkmn(Pkmn* pkmnAEditar, string nuevoNombre)
{
  pkmnAEditar->Nombre = nuevoNombre;
}



void ejecutarCodigoDePruebas()
{

  Pkmn* pk1 = CrearPokemon("pikachu", 25, 56, 78, 89);
  Pkmn* pk4 = CrearPokemon("charmander", 4, 50, 50, 50);
  Pkmn* pk5 = CrearPokemon("mew", 125, 156, 578, 809);
  Pkmn* pk6 = CrearPokemon("mewtwo", 1125, 1156, 1578, 1809);
  Pkmn* pk = CrearPokemon("YZY", 1125, 1156, 1578, 1809);
  //hardcoded values

  /*Inicio = pk1;
  pk1->Siguiente = pk4;
  pk4->Siguiente = pk5;
  pk5->Siguiente = pk6;*/

  //ImprimirLista();

  //string _Nombre;
  //int _Numero;
  //int _Ataque;
  //int _Defensa;
  //int _Velocidad;

  //cout << "Ingresa el nombre de un pokemon: ";
  //cin >> _Nombre;
  //cout << "Ingresa el numero de un pokemon: ";
  //cin >> _Numero;
  //cout << "Ingresa el Ataque de un pokemon: ";
  //cin >> _Ataque;
  //cout << "Ingresa el Defensa de un pokemon: ";
  //cin >> _Defensa;
  //cout << "Ingresa el Velocidad de un pokemon: ";
  //cin >> _Velocidad;

  //Pkmn* pkUsuario = CrearPokemon(_Nombre, _Numero, _Ataque, _Defensa, _Velocidad);
  ////pk6->Siguiente = pkUsuario;

  ////ImprimirLista();

  //cout << "Ingresa el nombre de un pokemon: ";
  //cin >> _Nombre;
  //cout << "Ingresa el numero de un pokemon: ";
  //cin >> _Numero;
  //cout << "Ingresa el Ataque de un pokemon: ";
  //cin >> _Ataque;
  //cout << "Ingresa el Defensa de un pokemon: ";
  //cin >> _Defensa;
  //cout << "Ingresa el Velocidad de un pokemon: ";
  //cin >> _Velocidad;

  //Pkmn* pkUsuario2 = CrearPokemon(_Nombre, _Numero, _Ataque, _Defensa, _Velocidad);
  ////pkUsuario->Siguiente = pkUsuario2;


  InsertarPkmnAlFinalDeLaLista(pk1);
  InsertarPkmnAlFinalDeLaLista(pk4);
  InsertarPkmnAlFinalDeLaLista(pk5);
  InsertarPkmnAlFinalDeLaLista(pk);
  InsertarPkmnAlFinalDeLaLista(pk6);

  pk = CrearPokemon("YZY", 1125, 1156, 1578, 1809);


  //InsertarPkmnAlFinalDeLaLista(pkUsuario);
  //InsertarPkmnAlFinalDeLaLista(pkUsuario2);

  ImprimirListaEnConsola();


  string nombreAbuscar;
  cout << "Ingresa el nombre de un pokemon a buscar: ";
  cin >> nombreAbuscar;

  Pkmn* pkBuscado = BuscarPkmn(nombreAbuscar);


  if (pkBuscado == NULL)
    cout << "El pkmn no ha fue encontrado :( \n";
  else
  {
    EditarPkmn(pkBuscado, "Agumon xD");
  }

  ImprimirListaEnConsola();

}


void darDeAltaUnPokemon()
{
  string nombre;
  int numero,ataque,defensa,velocidad;

  int opcion = 0;

  do {
    system("cls");
    cout << "Menu de alta de pokemon" << endl;
    cout << "1-Alta desde consola" << endl;
    cout << "2-Alta desde archivo" << endl;
    cout << "3-Alta de pokemon fijo" << endl;
    cout << "4-Salir" << endl;
    cout << "Selecciona una opcion > ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
    {
      cout << "Ingresa el nombre de un pokemon: ";
      cin >> nombre;
      cout << "Ingresa el numero de un pokemon: ";
      cin >> numero;
      cout << "Ingresa el Ataque de un pokemon: ";
      cin >> ataque;
      cout << "Ingresa el Defensa de un pokemon: ";
      cin >> defensa;
      cout << "Ingresa el Velocidad de un pokemon: ";
      cin >> velocidad;

      Pkmn* p = CrearPokemon(nombre, numero, ataque, defensa, velocidad);
      InsertarPkmnAlFinalDeLaLista(p);
      cout << "Pokemon creado con exito desde consola" << endl;
      system("pause");
    }
    break;
    case 2:
    {
      fstream archivo;
      archivo.open("pkmn.txt", ios::in);
      archivo >> nombre;
      archivo >> numero;
      archivo >> ataque;
      archivo >> defensa;
      archivo >> velocidad;
      archivo.close();

      Pkmn* p = CrearPokemon(nombre, numero, ataque, defensa, velocidad);
      InsertarPkmnAlFinalDeLaLista(p);
      cout << "Pokemon creado con exito desde archivo" << endl;
      system("pause");
    }
    break;
    case 3:
    {
      Pkmn* p = CrearPokemon("Megachu", 123, 66, 77, 88);
      InsertarPkmnAlFinalDeLaLista(p);
      cout << "Pokemon fijo creado con exito" << endl;
      system("pause");
    }
    break;
    case 4:
    {
      cout << "Esta saliendo del menu de alta de pokemon, vas a regresar al menu principal...." << endl;
      system("pause");
    }
    break;
    break;
    default:
      cout << "Opcion no valida." << endl;
      system("pause");
      break;
    }
  } while (opcion != 4);
}

void guardarListaEnArchivoDeTexto()
{
  Pkmn* aux = Inicio;
  fstream archivo;
  archivo.open("pkmn.txt", ios::out);

  while (aux != NULL)
  {
    archivo << aux->Nombre << "\n";
    archivo << aux->Numero << "\n";
    archivo << aux->Ataque << "\n";
    archivo << aux->Defensa << "\n";
    archivo << aux->Velocidad << "\n";
    aux = aux->Siguiente;
  }
  archivo.close();
}

void cargarListaDesdeArchivo()
{
  string nombre;
  int numero, ataque, defensa, velocidad;

  fstream archivo;
  archivo.open("pkmn.txt", ios::in);

  while (!archivo.eof())
  //el ciclo se repite mientras el archivo NO (!)llegue al end of file (eof) o final del archivo
  {
    archivo >> nombre;
    archivo >> numero;
    archivo >> ataque;
    archivo >> defensa;
    archivo >> velocidad;
   
    Pkmn* p = CrearPokemon(nombre, numero, ataque, defensa, velocidad);
    InsertarPkmnAlFinalDeLaLista(p);
  }
  archivo.close();
}

int main()
{
  Inicio = NULL;
  cargarListaDesdeArchivo();
  int opcion = 0;

  do {
    system("cls");
    cout << "Menu" << endl;
    cout << "1-Alta de pokemon" << endl;
    cout << "2-Baja de pokemon" << endl;
    cout << "3-Edicion de pokemon" << endl;
    cout << "4-Listado de pokemon" << endl;
    cout << "5-Salir" << endl;
    cout << "Selecciona una opcion > ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
    {
      darDeAltaUnPokemon();
    }
      break;
    case 2:
    {
    }
    break;
    case 3:
    {
    }
    break;
    case 4:
    {
      ImprimirListaEnConsola();
      system("pause");
    }
    break;
    case 5:
    {
      cout << "Hasta luego!" << endl;
      system("pause");
    }
    break;
    default:
      cout << "Opcion no valida." << endl;
      system("pause");
      break;
    }
  } while (opcion != 5);

  guardarListaEnArchivoDeTexto();

}
