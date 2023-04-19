// Estructuras.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int CONTADOR_USUARIOS = 0;
int CONTADOR_SUCURSALES = 0;

enum TipoUsuario{ADMIN, CAJERO};

struct Fecha
{
  int dia, mes, anio;
};

struct Sucursal
{
  int IDSucursal;
  string nombre;
  string direccion;
  //Fecha fecha_apertura;
};

struct Usuario
{
  int IDUsuario;
  string nombre;
  int tipoUsuario;
  int idSucursal;
  Fecha fecha_de_ultimo_login;
  //Fecha fecha_de_registro;
};

void prueba()
{
  Sucursal suc[3];
  suc[0].IDSucursal = 1;
  suc[0].nombre = "Matriz";
  suc[0].direccion = "Colonia centro";

  suc[1].IDSucursal = 2;
  suc[1].nombre = "Apodaca";
  suc[1].direccion = "Colonia apodaca";

  suc[2].IDSucursal = 3;
  suc[2].nombre = "San nicolas centro";
  suc[2].direccion = "Colonia centro de San Nico";

  Usuario us[6];

  us[0].IDUsuario = 1;
  us[0].nombre = "Angelica";
  us[0].tipoUsuario = ADMIN;
  us[0].idSucursal = 1;

  us[1].IDUsuario = 2;
  us[1].nombre = "Ray";
  us[1].tipoUsuario = ADMIN;
  us[1].idSucursal = 1;

  us[2].IDUsuario = 3;
  us[2].nombre = "Oscar";
  us[2].tipoUsuario = CAJERO;
  us[2].idSucursal = 1;

  us[3].IDUsuario = 4;
  us[3].nombre = "Yaquelyn";
  us[3].tipoUsuario = CAJERO;
  us[3].idSucursal = 2;

  us[4].IDUsuario = 5;
  us[4].nombre = "Lizbeth";
  us[4].tipoUsuario = CAJERO;
  us[4].idSucursal = 3;

  us[5].IDUsuario = 6;
  us[5].nombre = "Jose";
  us[5].tipoUsuario = CAJERO;
  us[5].idSucursal = 3;

  /*for (int i = 0; i < 6; i++)
  {
    cout << "Nombre: " << us[i].nombre << endl;
    for (int j = 0; j < 3; j++)
    {
      if(us[i].idSucursal == suc[j].IDSucursal)
        cout << suc[j].nombre<< endl;
    }
  }*/


}

int main()
{
  Usuario usuarios[10];
  Sucursal sucursales[3];

  fstream archivo;
  archivo.open("usuarios.bin", ios::binary | ios::in);

  int cont_us = 0;
  while (!archivo.eof())
  {
    archivo.read((char*)&usuarios[cont_us], sizeof(Usuario));
    cont_us++;
    CONTADOR_USUARIOS++;
  }
  archivo.close();


  CONTADOR_USUARIOS--;
  //CONTADOR_USUARIOS = usuarios[cont_us - 1].IDUsuario + 1;

 
  sucursales[0].IDSucursal = 1;
  sucursales[0].nombre = "Matriz";
  sucursales[0].direccion = "Colonia centro";

  sucursales[1].IDSucursal = 2;
  sucursales[1].nombre = "Apodaca";
  sucursales[1].direccion = "Colonia apodaca";

  sucursales[2].IDSucursal = 3;
  sucursales[2].nombre = "San nicolas centro";
  sucursales[2].direccion = "Colonia centro de San Nico";









  int opcion = 0;
  do {
    system("cls");
    cout << "Menu" << endl;
    cout << "1-Alta" << endl;
    cout << "2-Listado" << endl;
    cout << "3-Editar" << endl;
    cout << "4-salir" << endl;
    cout << "Ingresa tu oopcion: ";
    cin >> opcion;
    switch (opcion)
    {
    case 1:
    {
      usuarios[CONTADOR_USUARIOS].IDUsuario = CONTADOR_USUARIOS;
      cout << "Ingresa el nombre del usuario #" << CONTADOR_USUARIOS + 1 << ": ";
      cin >> usuarios[CONTADOR_USUARIOS].nombre;
      cout << "Listado de sucursales" << endl;
      for (int j = 0; j < 3; j++)
      {
        cout << "\t" << sucursales[j].IDSucursal << " - " << sucursales[j].nombre << endl;
      }
      cout << "Selecciona la sucursal del cliente: ";
      cin >> usuarios[CONTADOR_USUARIOS].idSucursal;
      CONTADOR_USUARIOS++; 
      

    }
    break;
    case 2:
    {
      cout << "Listado de usuarios" <<endl;
      for (int i = 0; i < CONTADOR_USUARIOS; i++)
      {
        cout << "ID del usuario: " << usuarios[i].IDUsuario << endl;
        cout << "Nombre: " << usuarios[i].nombre << endl;
        for (int j = 0; j < 3; j++)
        {
          if (usuarios[i].idSucursal == sucursales[j].IDSucursal)
            cout << sucursales[j].nombre << endl;
        }
      }
      system("pause");
    }
    break;
    case 3:
    {}
    break;
    }
  } while (opcion != 4);



  //fstream archivo;
  archivo.open("usuarios.bin", ios::binary | ios::out);
  for (int i = 0; i < CONTADOR_USUARIOS; i++)
  {
    archivo.write((char*)&usuarios[i], sizeof(Usuario));
  }
  archivo.close();


}

