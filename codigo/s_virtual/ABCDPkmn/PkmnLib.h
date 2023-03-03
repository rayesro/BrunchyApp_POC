//Pokemon - libreria de funciones
#pragma once
#include<string>
using namespace std;

int CantidadPokemon = 50;


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
