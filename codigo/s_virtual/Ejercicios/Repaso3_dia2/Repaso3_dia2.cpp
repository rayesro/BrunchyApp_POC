// Repaso3_dia2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

struct FechaDeNacimiento
{
  int dia;
  int mes;
  int anio;

  string obtenerFechaDDMMAAAA()
  {
    //string temp = to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);
    string temp = to_string(dia) + " de ";
    switch (mes)
    {
    case 1: temp += "enero "; break;
    case 2: temp += "febrero "; break;
    case 3: temp += "marzo "; break;
    case 4: temp += "abril "; break;
    case 5: temp += "mayo "; break;
    case 6: temp += "junio "; break;
    case 7: temp += "julio "; break;
    case 8: temp += "agosto "; break;
    case 9: temp += "sept "; break;
    case 10: temp += "oct "; break;
    case 11: temp += "nov "; break;
    case 12: temp += "diciembre "; break;
    }
    temp += "del " + to_string(anio);

    return temp;
  }
};

struct Usuario
{
  string nombre;
  string apellido;
  FechaDeNacimiento fechaDeNacimiento;

  string obtenerNombreCompleto()
  {
    string temp = nombre + " " + apellido;
    return temp;
  }
};

Usuario usuarios[10];
int contUsuarios = 0;

void imprimirMensajeDePausa();
int imprimeYCapturaOpcionDeMenu(string titulo, string opciones[], int cantidadDeOpciones);
void imprimirMenuPrincipal();
void imprimirMenuUsuarios();
void imprimirMenuClientes();
void imprimirMenuPromociones();

int main()
{
  imprimirMenuPrincipal();
}


// Hacer una funcion para agregar un usuario al listado
// que reciba como datos de entrada:
// nombre, apellido, dia , mes y anio
// y que regrese nada

void agregarUsuario(string nombre, string apellido, int dia, int mes, int anio)
{
  Usuario user;
  user.nombre = nombre;
  user.apellido = apellido;
  user.fechaDeNacimiento.dia = dia;
  user.fechaDeNacimiento.mes = mes;
  user.fechaDeNacimiento.anio = anio;

  usuarios[contUsuarios] = user;
  contUsuarios++;
}


void imprimirMensajeDePausa()
{
  cout << " >>> Presiona una tecla para continuar..." << endl;
  cin.get();
  cin.ignore();
}

int imprimeYCapturaOpcionDeMenu(string titulo, string opciones[], int cantidadDeOpciones)
{
  int opcion = 0;
  do {
    system("cls");
    cout << "-:-:-" << titulo << "-:-:-" << endl;
    for (int i = 0; i < cantidadDeOpciones; i++)
    {
      cout << " " << i + 1 << "]- " << opciones[i] << endl;
    }
    cout << "Selecciona una opcion>>> ";
    cin >> opcion;
    if (opcion < 1 || opcion > cantidadDeOpciones)
    {
      cout << " Esa opcion no es valida. Ingresa una opcion del menu." << endl;
      imprimirMensajeDePausa();
    }
  } while (opcion<1 || opcion>cantidadDeOpciones);
  return opcion;
}

void imprimirMenuPrincipal()
{
  string opcs[] = { "Usuarios", "Clientes", "Promociones", "Salir" };
  int opcion = imprimeYCapturaOpcionDeMenu("Menu principal", opcs, 4);
  switch (opcion)
  {
  case 1:
  {
    imprimirMenuUsuarios();
    break;
  }
  case 2:
  {
    imprimirMenuClientes();
    break;
  }
  case 3:
  {
    imprimirMenuPromociones();
    break;
  }
  case 4:
  {
    cout << "\t  Adios! Vuelve pronto!!!!!!!" << endl;
    break;
  }
  default:
    cout << "\t Esa opcion no es valida. Ingresa una opcion del menu." << endl;
    break;
  }
}

void imprimirMenuUsuarios() 
{
  string opciones[] = {
    "Alta de usuarios",
    "Baja de usuarios",
    "Editar usuario",
    "Listado de usuarios",
    "Regresar al menu principal" };
  int opcion = imprimeYCapturaOpcionDeMenu("Menu de Usuarios", opciones, 5);

  switch (opcion)
  {
  case 1:
  {
    cout << " === Has entrado al submenu de alta de usuarios === " << endl;
    agregarUsuario("Ray", "Espinosa", 19,11,1991);
    agregarUsuario("Roy", "Roque", 20, 12, 1990);
    imprimirMenuPrincipal();
    break;
  }
  case 2:
  {
    cout << " === Has entrado al submenu de Baja de usuarios === " << endl;
    break;
  }
  case 3:
  {
    cout << " === Has entrado al submenu de Editar de usuarios === " << endl;
    break;
  }
  case 4:
  {
    cout << " === Has entrado al submenu de Listado de usuarios === " << endl;
    for (int i = 0; i < contUsuarios; i++)
    {
      //cout << "Nombre................." << usuarios[i].nombre << " " << usuarios[i].apellido<< endl;
      cout << "Nombre................." << usuarios[i].obtenerNombreCompleto() << endl;
      cout << "Fecha de nacimiento...." << usuarios[i].fechaDeNacimiento.obtenerFechaDDMMAAAA() << endl;
     /* cout << "Fecha de nacimiento...." << usuarios[i].fechaDeNacimiento.dia 
        << "-" << usuarios[i].fechaDeNacimiento.mes 
        << "-" << usuarios[i].fechaDeNacimiento.anio
        << endl;*/
    }
    break;
  }
  case 5:
  {
    imprimirMenuPrincipal();
    break;
  }
  }
 }

void imprimirMenuClientes() 
{

  string opciones[] = {
    "Alta de clientes",
    "Baja de clientes",
    "Editar usuario",
    "Listado de clientes",
    "Salir" };
  int opcion = imprimeYCapturaOpcionDeMenu("Menu de clientesitos", opciones, 5);

  switch (opcion)
  {
  case 1:
  {
    cout << " === Has entrado al submenu de alta de clientes === " << endl;
    break;
  }
  case 2:
  {
    cout << " === Has entrado al submenu de Baja de clientes === " << endl;
    break;
  }
  case 3:
  {
    cout << " === Has entrado al submenu de Editar de clientes === " << endl;
    break;
  }
  case 4:
  {
    cout << " === Has entrado al submenu de Listado de clientes === " << endl;
    break;
  }
  case 5:
  {
    cout << "\t  Adios! Vuelve pronto!!!!!!!" << endl;
    break;
  }
  }
}

void imprimirMenuPromociones() 
{
  system("cls");
  cout << "-:;-:-:Menu de promociones-:;-:-:" << endl;
  cout << "1] Alta de promociones. " << endl;
  cout << "2] Baja de promociones. " << endl;
  cout << "3] Editar promocion. " << endl;
  cout << "4] Listado de promociones. " << endl;
  cout << "5] Salir. " << endl;
}


