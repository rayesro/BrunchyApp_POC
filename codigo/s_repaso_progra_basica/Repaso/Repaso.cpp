// Repaso.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>

using namespace std;

struct Domicilio
{
  string Calle;
  int Numero;
  int CodigoPostal;
  string Colonia;
  string EntreCalles;
  string NumeroInterior;
  string Estado;
  string Municipio;
  string Pais;
  string Referencia;
};

//Estructura es un conjunto de datos agrupados bajo un mismo nombre, los datos puedes ser de diferente tipo
struct Usuario
{
  string Nombre;
  string ApellidoPat;
  string ApellidoMat;
  string NombreUsuario;
  Domicilio Casa;
  Usuario* Sig;
};

struct Sucursal
{
  string Nombre;
  Domicilio DomicilioSuc;
};

struct Empresa 
{
  string Nombre;
  string RFC;
  int TotalDeEmpleados;
  bool EsSucursalMatriz;
  Domicilio DomicilioPrincipal;
  Domicilio DomiciliosSucursales[10];
};

/*
tipo_de_dato_de_retorno nombre(parametros)
{
  cuerpo de la funcion
}
*/

//int, char, float, bool, string, short, double

void ImprimirHolaMundo()
{
  cout << "HOLA MUNDO!!" << endl;
}

int calcularSuma()
{
  int x = 10;
  int y = 10;
  int z = x + y;
  return z;
}

float calcularResta(int x, int z)
{
  float a = x - z;
  return a;
}

Usuario* CrearUsuario(string nom, string apPat, string apMat)
{
  Usuario* us = new Usuario;
  us->Nombre = nom;
  us->ApellidoPat = apPat;
  us->ApellidoMat = apMat;
  us->Sig = NULL;
  return us;
}

Domicilio* GenerarDomicilio(int calle, int num)
{
  Domicilio* dom = new Domicilio;
  dom->Calle = calle;
  dom->Numero = num;
  return dom;
}

Sucursal CrearSucursal(string nombre)
{
  Sucursal s;
  s.Nombre = nombre;
  return s;
}

int main()
{
  Sucursal s1 = CrearSucursal("suc1");



  Usuario usuario1;
  usuario1.Nombre = "Raymundo";

  cout << "El nombre del usuario es " << usuario1.Nombre << endl;

  Usuario usuarios[10];//???
  usuarios[0].Nombre = "Ray";
  usuarios[1].Nombre = "Angy";
  usuarios[2].Nombre = "Ary";

  for (int i = 0; i < 10; i++)
  {
    cout << "El nombre del usuario es " << usuarios[i].Nombre << endl;
  }

  int* ptr;
  Usuario* usuarioPtr;
  usuarioPtr = new Usuario;

  usuarioPtr->Nombre = "Mundo";
  cout << "El nombre del usuario es " << usuarioPtr->Nombre << endl;
  usuarioPtr->ApellidoPat = "es";
  usuarioPtr->ApellidoMat = "ro";
  usuarioPtr->NombreUsuario = "rayesro";



  Usuario* usuarioPrincipalPtr;
  usuarioPrincipalPtr = new Usuario;
  usuarioPrincipalPtr->Nombre = "Goku";


  usuarioPrincipalPtr->Casa.CodigoPostal = 123456;
  usuarioPrincipalPtr->Casa.Pais = "Mexico";
  usuarioPrincipalPtr->Casa.Calle = "Calle de las nubes voladoras";

  Usuario* us2;



}