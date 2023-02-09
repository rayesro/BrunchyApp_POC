// Repaso.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
  //Estructuras de control - if

  char nombreDeAlumno[] = "Ray==mundo";

  int edad = 10;

  cout << "HOLA, MUNDO!!" << endl;

  if (edad >= 18)
    cout << "Puedes comprar cerveza!!! Salud!!" << endl;
  else
    cout << "Eres menor de edad, no puedes beber cerveza." << endl;

  cout << endl << endl << "___________________________________" << endl << endl;
  float calif1 = 61.43;
  float calif2 = 88.92;
  float calif3 = 95;

  float promedio = (calif1 + calif2 + calif3) / 3;

  cout << "Tu promedio es " << promedio << endl;

  // Hacer que el programa notifique al usuario o decirle al usuario que calificaciones son mayores que su promedio
  if (calif1 > promedio)
    cout << "Tu calificacion 1 es mayor que tu promedio" << endl;

  if (calif2 > promedio)
    cout << "Tu calificacion 2 es mayor que tu promedio" << endl;

  if (calif3 > promedio)
    cout << "Tu calificacion 3 es mayor que tu promedio" << endl;

  cout << endl << endl << "___________________________________" << endl << endl;

  // Como hacemos para decirle al usuario que todas sus calificaciones son mayores al promedio
  if (calif1 > promedio && calif2 > promedio && calif3 > promedio)
  {
    cout << "Muchas felicidades por tu esfuerzo!!!" << endl;
  }
  else
  {
    cout << "Sigue intentadolo!!!" << endl;
  }

  cout << endl << endl << "___________________________________" << endl << endl;

  if (calif1 < promedio)
  {
    cout << "Estudia un poco mas en el siguiente examen para obtener mejor calificacion." << endl;

  }
  else if (calif2 < promedio)
  {
    cout << "Estudia un poco mas en tu utlimo examen para obtener mejor calificacion." << endl;
  }
  else if (calif3 < promedio)
  {
    cout << "Preparate mentalmente porque probablemente no pases la materia." << endl;
  }
  else
  {
    cout << "Todas tus calificaciones son mayores al promedio" << endl;
  }

  cout << endl << endl << "___________________________________" << endl << endl;


  int opcion = 0;
  do {
    // ejemplos de uso del switch
    cout << "__MENU PRINCIPAL__" << endl;
    cout << " 1) Menu de alta de clientes" << endl;
    cout << " 2) Menu de alta de productos" << endl;
    cout << " 3) Menu de listado de productos" << endl;
    cout << " 4) Menu de listado de clientes" << endl;
    cout << " 5) Salir" << endl;
    cout << "Selecciona una opcion: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
    {
      cout << endl << endl << "Entraste al menu de alta de clientes" << endl;
      break;
    }
    case 2:
    {
      cout << endl << endl << "Entraste al menu de alta de productos" << endl;
      break;
    }
    case 3:
    {
      cout << endl << endl << "Entraste al menu de listado de productos" << endl;
      break;
    }
    case 4:
      cout << endl << endl << "Entraste al menu de listado de clientes" << endl;
      break;
    case 5:
      cout << endl << endl << "Adios!!" << endl;
      break;
    default:
      cout << "Opcion no valida" << endl;
      cout << "Ingrese una opcion valida" << endl;
      break;
    }
  } while (opcion < 1 || opcion > 5);

  int contador = 0;
  while (contador < 10)
  {
    cout << nombreDeAlumno[contador];
    contador++;// contador = contador + 1;
  }
  cout << endl << endl << endl;

  cout << endl << endl << "___________________________________" << endl << endl;

  for (int i = 0; i < 10; i++)
  {
    cout << nombreDeAlumno[i] << ".";
  }

  cout << endl << endl << "___________________________________" << endl << endl;


  for (int i = 9; i >= 0; i = i - 1) // i = i -1
  {
    cout << nombreDeAlumno[i] << ".";
  }

  cout << endl << endl << "___________________________________" << endl << endl;
}

