// ABCPkmn.cpp : This file contains the 'main' function. Program execution begins and ends there.
//scope ==> alcance

#include <iostream>
#include "PkmnLib.h"

using namespace std;



int main()
{
  Inicio = NULL;

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

  Pkmn* pk = CrearPokemon("YZY", 1125, 1156, 1578, 1809);
  
  
  //InsertarPkmnAlFinalDeLaLista(pkUsuario);
  //InsertarPkmnAlFinalDeLaLista(pkUsuario2);

  ImprimirListaEnConsola();


  string nombreAbuscar;
  cout << "Ingresa el nombre de un pokemon a buscar: ";
  cin >> nombreAbuscar;

  Pkmn* pkBuscado = BuscarPkmn(nombreAbuscar);
  
  
  if(pkBuscado == NULL)
    cout << "El pkmn no ha fue encontrado :( \n";
  else
  {
    EditarPkmn(pkBuscado, "Agumon xD");
  }

  ImprimirListaEnConsola();



}
