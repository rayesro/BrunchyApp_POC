// Grupo4_ListasLigadasSimples.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Grupo4_ListasLigadasSimples.h"

using namespace std;

struct FechaDeNacimiento
{
  int dia;
  int mes;
  int anio;
};

struct Cliente
{
  int IdCliente;
  string Nombre;
  string Apellido;
  FechaDeNacimiento FechaNacimiento;
  Cliente* siguiente;
  Cliente* anterior;
};

void InsertarNodosEnLista();
void BuscarNodosEnLista();
void BorrarNodoDeLista();

int main()
{

}


void InsertarNodosEnLista()
{
  Cliente* ListaConNodosSiempreAlInicio = NULL;
  Cliente* ListaConNodosSiempreAlFinal = NULL;


  Cliente* cliente1 = new Cliente;
  cliente1->IdCliente = 1;
  cliente1->Nombre = "Raymundo";
  cliente1->Apellido = "Espinosa";
  cliente1->FechaNacimiento.dia = 19;
  cliente1->FechaNacimiento.mes = 9;
  cliente1->FechaNacimiento.anio = 1991;
  cliente1->siguiente = NULL;

  //insercion

  Cliente* cliente2 = new Cliente;
  cliente2->IdCliente = 2;
  cliente2->Nombre = "Angelica";
  cliente2->Apellido = "Garcia";
  cliente2->FechaNacimiento.dia = 20;
  cliente2->FechaNacimiento.mes = 8;
  cliente2->FechaNacimiento.anio = 1995;
  cliente2->siguiente = NULL;

  //insercion

  Cliente* cliente3 = new Cliente;
  cliente3->IdCliente = 3;
  cliente3->Nombre = "Jose";
  cliente3->Apellido = "Lopez";
  cliente3->FechaNacimiento.dia = 30;
  cliente3->FechaNacimiento.mes = 1;
  cliente3->FechaNacimiento.anio = 2000;
  cliente3->siguiente = NULL;



  Cliente* cliente4 = new Cliente;
  cliente4->IdCliente = 3;
  cliente4->Nombre = "Juan";
  cliente4->Apellido = "Perez";
  cliente4->FechaNacimiento.dia = 3;
  cliente4->FechaNacimiento.mes = 10;
  cliente4->FechaNacimiento.anio = 1990;
  cliente4->siguiente = NULL;


  //insercion


  //Insertando nodos siempre al inicio de la lista
  /*ListaConNodosSiempreAlInicio = cliente1;
  cliente2->siguiente = cliente1;
  ListaConNodosSiempreAlInicio = cliente2;
  cliente3->siguiente = cliente2;
  ListaConNodosSiempreAlInicio = cliente3;*/




  //Insertando nodos siempre al final de la lista
  ListaConNodosSiempreAlFinal = cliente1;
  cliente1->siguiente = cliente2;
  cliente2->siguiente = cliente3;

  cliente1->siguiente = cliente4;
  cliente4->siguiente = cliente2;
}

void BuscarNodosEnLista()
{
  Cliente* InicioLista = NULL;

  for (int i = 0; i < 10; i++)
  {
    Cliente* cliente = new Cliente;
    cliente->IdCliente = i + 1;
    cliente->Nombre = 65 + i; // Una letra mayus de nombre
    cliente->Apellido = 97 + i; // Una letra minus de nombre
    cliente->FechaNacimiento.dia = 19;
    if( i % 2 == 0 )
      cliente->FechaNacimiento.mes = i + 1;
    else
      cliente->FechaNacimiento.mes = i ;
    cliente->FechaNacimiento.anio = 1991;
    cliente->siguiente = NULL;


    if (InicioLista == NULL)
    {
      InicioLista = cliente;
    }
    else
    {
      Cliente* aux = InicioLista;
      while (aux->siguiente != NULL)
      {
        aux = aux->siguiente;
      }
      aux->siguiente = cliente;
    }
  }//fin del for

  ////busqueda por mes
  //int mes = 0;
  //cout << "Ingresa el mes de nacimiento del cliente que deseas buscar: ";
  //cin >> mes;

  //Cliente* aux = InicioLista;
  //while (aux != NULL && aux->FechaNacimiento.mes != mes)
  //{
  //  aux = aux->siguiente;
  //}

  //if (aux != NULL)
  //{
  //  cout << "Nombre del cliente : " << aux->Nombre << " " << aux->Apellido << endl;
  //  cout << "Fecha de nacimiento: " << aux->FechaNacimiento.dia << "-" << aux->FechaNacimiento.mes << "-" << aux->FechaNacimiento.anio << endl;
  //}
  //else
  //{
  //  cout << "No se encontro un cliente que naciera en el mes #" << mes;
  //}

  //cout << endl << endl << endl;
  ////busqueda por dia

  //int dia = 0;
  //cout << "Ingresa el dia de nacimiento del cliente que deseas buscar: ";
  //cin >> dia;

  //aux = InicioLista;
  //while (aux != NULL && aux->FechaNacimiento.dia != dia)
  //{
  //  aux = aux->siguiente;
  //}

  //if (aux != NULL)
  //{
  //  cout << "Nombre del cliente : " << aux->Nombre << " " << aux->Apellido << endl;
  //  cout << "Fecha de nacimiento: " << aux->FechaNacimiento.dia << "-" << aux->FechaNacimiento.mes << "-" << aux->FechaNacimiento.anio << endl;
  //}
  //else
  //{
  //  cout << "No se encontro un cliente que naciera en el mes #" << mes;
  //}

  //busqueda por mes de todos los que coincidan
  int mes = 0;
  Cliente* ListaDeTodosLosClientesConMismoMes = NULL;
  cout << "Ingresa el mes de nacimiento: ";
  cin >> mes;

  Cliente* aux = InicioLista;
  while (aux != NULL)
  {
    if (aux->FechaNacimiento.mes == mes)
    {
      Cliente* nuevoCliente = new Cliente;
      nuevoCliente->IdCliente  = aux->IdCliente;
      nuevoCliente->Nombre = aux->Nombre;
      nuevoCliente->Apellido = aux->Apellido;
      nuevoCliente->FechaNacimiento = aux->FechaNacimiento;
      nuevoCliente->siguiente = NULL;

      if (ListaDeTodosLosClientesConMismoMes == NULL)
      {
        ListaDeTodosLosClientesConMismoMes = nuevoCliente;
      }
      else
      {
        Cliente* aux2 = ListaDeTodosLosClientesConMismoMes;
        while (aux2->siguiente != NULL)
        {
          aux2 = aux2->siguiente;
        }
        aux2->siguiente = nuevoCliente;
      }
    }
    aux = aux->siguiente;
  }

  aux = ListaDeTodosLosClientesConMismoMes;
  while (aux != NULL)
  {
    cout << "Nombre del cliente : " << aux->Nombre << " " << aux->Apellido << endl;
    cout << "Fecha de nacimiento: " << aux->FechaNacimiento.dia << "-" << aux->FechaNacimiento.mes << "-" << aux->FechaNacimiento.anio << endl;
    aux = aux->siguiente;
  }


}

void BorrarNodoDeLista()
{
  Cliente* InicioLista = NULL;

  for (int i = 0; i < 10; i++)
  {
    Cliente* cliente = new Cliente;
    cliente->IdCliente = i + 1;
    cliente->Nombre = 65 + i; // Una letra mayus de nombre
    cliente->Apellido = 97 + i; // Una letra minus de nombre
    cliente->FechaNacimiento.dia = 19;
    cliente->FechaNacimiento.mes = i + 1;
    cliente->FechaNacimiento.anio = 1991;
    cliente->siguiente = NULL;


    if (InicioLista == NULL)
    {
      InicioLista = cliente;
    }
    else
    {
      Cliente* aux = InicioLista;
      while (aux->siguiente != NULL)
      {
        aux = aux->siguiente;
      }
      aux->siguiente = cliente;
    }
  }



  if (InicioLista == NULL)
  {
    cout << "No hay datos en la lista";
    return;
  }
  //busqueda por mes
  int mes = 0;
  cout << "Ingresa el mes de nacimiento del cliente que deseas buscar: ";
  cin >> mes;

  

  Cliente* clienteAEliminar = InicioLista;
  while (clienteAEliminar != NULL && clienteAEliminar->FechaNacimiento.mes != mes)
  {
    clienteAEliminar = clienteAEliminar->siguiente;
  }

  if (clienteAEliminar == NULL)
  {
    cout << "No se encontro un cliente que naciera en el mes #" << mes;
  }
  else
  {
    if (clienteAEliminar == InicioLista)
    {
      InicioLista = InicioLista->siguiente;
    }
    else if (clienteAEliminar->siguiente == NULL)
    {
      Cliente* aux = InicioLista;
      while (aux->siguiente != clienteAEliminar)
      {
        aux = aux->siguiente;
      }
      aux->siguiente = NULL;
    }
    else
    {
      Cliente* aux = InicioLista;
      while (aux->siguiente != clienteAEliminar)
      {
        aux = aux->siguiente;
      }
      aux->siguiente = clienteAEliminar->siguiente;
    }
    delete clienteAEliminar;
  }

  Cliente* temp = InicioLista;
  while (temp != NULL)
  {
    cout << "Nombre del cliente : " << temp->Nombre << " " << temp->Apellido << endl;
    cout << "Fecha de nacimiento: " << temp->FechaNacimiento.dia << "-" << temp->FechaNacimiento.mes << "-" << temp->FechaNacimiento.anio << endl;
    temp = temp->siguiente;
  }


}