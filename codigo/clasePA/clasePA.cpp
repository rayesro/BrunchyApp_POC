// clasePA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include "clasePA.h"
using namespace std;

void inicioDeSesion()
{
  string usuario;
  string contrasena;
  cout << "Ingresa tu usuario: ";
  cin >> usuario;
  cout << "Ingresa tu contrasena: ";
  cin >> contrasena;
  cout << "Tu nombre es: " << usuario << endl;
  cout << "Tu contrasena es: " << contrasena << endl;
} 

void suma()
{
  int a = 12;
  int b = 18;
  int c = a + b;
  cout << c;
}

int restar(int a, int b)
{
  return a - b;
}

void pedirEImprimirEdad(int numUsuario, string titulo)
{
  int edad1 = 0;
  cout << "Ingresa tu edad " << titulo << " #" << numUsuario << endl;
  cin >> edad1;
  if (edad1 >= 18)
    cout << "Es mayor de edad " << titulo << " #" << numUsuario << endl;
  else
    cout << "Es menor de edad " << titulo << " #" << numUsuario << endl;
}

void multiplicacion(int x, int y)
{
  int z = x * y;
  x = z;
  cout << z << endl; // 20
}

void ejemploDePunteros()
{
  int edades[10];

  int* ptrEdades;
  ptrEdades = new int[10];


  for (int i = 0; i < 1000000; i++)
  {
    ptrEdades = new int[1000000000];
    /// al terminar 
    delete ptrEdades;
  }

  for (int i = 0; i < 10; i++)
  {
    ptrEdades[i] = (i + 1) * 10;
  }

  delete ptrEdades;

  //hicimos algo y queremos mas
  ptrEdades = new int[100000];
  delete ptrEdades;

  //todavia queremos mas
  ptrEdades = new int[30000000];
  delete ptrEdades;


  //instruccion para imprimir
  //cout


  for (int i = 0; i < 10; i++)
  {
    //con este codigo imprimimos usando el indice del arreglo
   /* cout << "Edades # " << i + 1 << ":" <<
      edades[i] << endl;*/
      //con este codigo imprimimos usando el punteros
    cout << "Edades # " << i + 1 << ":" <<
      *(ptrEdades + i) << endl;
  }

  //return 0;
//  cout << "La edad 1 es " << *(edades + 1) << endl;
  //cout << "La edad 8 es " << *(edades + 8) << endl;

  int* ptrArr;
  ptrArr = &edades[0];
  for (int i = 0; i < 10; i++)
  {
    cout << "Edades con ptr# " << i + 1 << ":" <<
      *ptrArr << endl; //*(ptrArr + 1)
    ptrArr++;
  }

  //cout << "La edad 1 con ptrArr es " << *ptrArr << endl;
  //ptrArr++; // ptrArr = ptrArr + 1;
  //cout << "La edad 1 con ptrArr es " << *ptrArr << endl;

  int x = 99;
  int* p;
  p = &x;
  //cout << endl << endl << endl << endl;
  //cout << p; // la direccion de memoria de X
  //cout << *p;// el valor o contenido de x, en este caso 10
  //cout << &p;//la direccion propia del puntero p

  //con el return 0 terminamos la aplicacion
 // return 0;




  //////int valor_e = 100;
  //////int* ptr1 = &valor_e;
  //////int** ptr2 = &ptr1;

  //////cout << "ptr1: " << ptr1 << endl;
  //////cout << "&ptr1: " << &ptr1 << endl;
  //////cout << "*ptr1: " << *ptr1 << endl;
  //////cout << "ptr2: " << ptr2 << endl;
  //////cout << "&ptr2: " << &ptr2 << endl;
  //////cout << "*ptr2: " << *ptr2 << endl;
  //////cout << "**ptr2: " << **ptr2 << endl;

  ////////void* pointer = NULL;
  //////int n = 7;
  //////float pi = 3.141592;

  ////////pointer = &n;//puntero tipo void apunta a una direccion de un entero
  ////////cout << " &pointer = " << pointer << endl;
  ////////pointer = &pi;//puntero tipo void apunta a una direccion de un flotante
  ////////cout << " &pointer = " << pointer << endl;

  ////////// explicit cast, casteo explicito
  ////////float* ptrToVoid = (float*)pointer;
  ////////cout << *ptrToVoid;
  ////////casting


  //////float* f;
  //////f = NULL;
  ////////float pi = 3.141592;
  //////f = &pi;

  //////if (f == NULL)
  //////  cout << "f es igual a NULL" << endl;

  //////if (f)//if(f != NULL)
  //////  cout << "f es diferente a NULL" << endl;


  ////// n = 75;
  //////int* p = &n;

  //////cout << " n  = " << n << endl;
  //////cout << " &n = " << &n << endl;
  //////cout << " p  = " << p << endl;
  //////cout << " &p = " << &p << endl;
  //////cout << " *p = " << *p << endl;


  //////int a = 4, b = 5;
  //////multiplicacion(a, b);

  //////cout << a << " " << b; // 20 5

  //////return 0;
  //////////inicioDeSesion();
  //////////inicioDeSesion();
  ////////
  //////////suma();
  /////////*{
  ////////  int c = 12;
  ////////  int z = 12;
  ////////  cout << "El valor de la suma es " << c;
  ////////}
  ////////cout << "El valor de z es " << z;*/

  ////////int x = 0;
  ////////int r = 0;

  ////////cout << "Ingresa el valor de x";
  ////////cin >> x;
  ////////cout << "Ingresa el valor de r";
  ////////cin >> r;


  ////////int resta = 0;
  ////////resta = restar(x,r);

  ////////cout << "El valor de la resta es " << resta;

  //////int edad1 = 0;
  //////int edad2 = 0;
  //////int edad3 = 0;



  //////for (int i = 0; i < 5; i++)
  //////{
  //////  if(i%2==0)
  //////    pedirEImprimirEdad(i+1,"maestro");
  //////  else
  //////    pedirEImprimirEdad(i + 1, "alumno");
  //////}

}

struct Pkmn {
  string nombre;
  int atk;
};

int main()
{
  //Definimos un nodo que se llama Pokemon
  struct Pokemon {
    //datos
    string nombre;
    int atk;
    //enlace
    Pokemon* enlace;
  };

  int contador = 0;


  //definimos el puntero al inicio u origen de la lista
  Pokemon* Inicio = NULL;

  //creamos un nuevo nodo(nuevo pokemon)
  Pokemon* pkmn1 = new Pokemon;
  //asignamos informacion a los miembros del nodo (pokemon)
  pkmn1->nombre = "mew";
  pkmn1->atk = 99;
  pkmn1->enlace = NULL;

  Pokemon* pkmn2 = new Pokemon;
  //asignamos informacion a los miembros del nodo (pokemon)
  pkmn2->nombre = "mew2";
  pkmn2->atk = 100;
  pkmn2->enlace = NULL;

  Pokemon* pkmn3 = new Pokemon;
  //asignamos informacion a los miembros del nodo (pokemon)
  pkmn3->nombre = "mew3";
  pkmn3->atk = 1001;
  pkmn3->enlace = NULL;

  Pokemon* pkmn4 = new Pokemon;
  //asignamos informacion a los miembros del nodo (pokemon)
  pkmn4->nombre = "m";
  pkmn4->atk = 99;
  pkmn4->enlace = NULL;


  
  Inicio = pkmn1;
  pkmn1->enlace = pkmn2;
  pkmn2->enlace = pkmn3;

  pkmn4->enlace = Inicio;
  Inicio = pkmn4;

  






  
 
}

void ejemploDeArreglosDinamicos()
{
  int cantidadDePkmns = 0;
  cout << "Ingresa la cantidad de pkmns que quieres tener: ";
  cin >> cantidadDePkmns;
  Pkmn* pkmns;

  //Pkmn pk1;
  //pk1.nombre = "mew";

  //Pkmn* pk2;
  //pk2->nombre = "";

  pkmns = new Pkmn[cantidadDePkmns];

  for (int i = 0; i < cantidadDePkmns; i++)
  {
    cout << "Dime el nombre de tu pkmn #" << i + 1 << ":";
    cin >> pkmns[i].nombre;
  }

  for (int i = 0; i < cantidadDePkmns; i++)
  {
    cout << "Pkmn #" << i + 1 << " =>" << pkmns[i].nombre << endl;
  }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
