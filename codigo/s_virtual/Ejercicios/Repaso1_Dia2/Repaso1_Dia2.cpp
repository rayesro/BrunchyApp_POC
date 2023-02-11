// Repaso1_Dia2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
  int edad = 0;
  cout << "Ingresa tu edad: ";
  cin >> edad;
  cout << "Usuario, tu edad es " << edad << endl;//endl => end line
  // El programa debe decirle al usuario si puede jugar juegos tipo E, E10+, T, M17+, Ao

  //if (edad < 18)
  //{
  //  cout << "No puedes jugar videojuegos tipo Ao" << endl;
  //}

  //cout << endl << endl << "______________________" << endl << endl;


  //if (edad >= 18)
  //{
  //  cout << "Puedes jugar videojuegos tipo E, E10+, T, M17+ y Ao" << endl;
  //}
  //else 
  //{
  //  cout << "Puedes jugar videojuegos tipo E, E10+, T y M17+" << endl;
  //}

  //cout << endl << endl << "______________________" << endl << endl;

  if (edad < 10)
  {
    cout << "Puedes jugar videojuegos tipo E" << endl;
  }
  else if (edad < 13)
  {
    cout << "Puedes jugar videojuegos tipo E y E10+" << endl;
  }
  else if (edad < 17)
  {
    cout << "Puedes jugar videojuegos tipo E, E10+ y T" << endl;
  }
  else if (edad < 18)
  {
    cout << "Puedes jugar videojuegos tipo E, E10+, T y M17+" << endl;
  }
  else
    cout << "Puedes jugar videojuegos tipo E, E10+, T, M17+ y Ao" << endl;


  cout << endl << endl << "______________________" << endl << endl;

  char opcionMenu = 0;
  do {
    
    cout << "Menu de clasificaciones y videojuegos" << endl;
    cout << " a) Videjuegos tipo E" << endl;
    cout << " b) Videjuegos tipo E10+" << endl;
    cout << " c) Videjuegos tipo T" << endl;
    cout << " d) Videjuegos tipo M17+" << endl;
    cout << " e) Videjuegos tipo Ao" << endl;
    cout << " f) Salir" << endl;
    cout << " Selecciona tu opcion: ";
    cin >> opcionMenu;

    switch (opcionMenu)
    {
    case 'a':
    case 'A':
    {
      cout << "Puedes jugar el videojuego de Plaza Sesamo y de Dora la explora" << endl;
      break;
    }
    case 'b':
    {
      cout << "Puedes jugar el videojuego de Bob esponja" << endl;
      break;
    }
    case 'c':
    {
      cout << "Puedes jugar el videojuego de Fortnite" << endl;
      break;
    }
    case 'd':
    {
      cout << "Puedes jugar el videojuego de Mortal Kombat" << endl;
      break;
    }
    case 'e':
    {
      if (edad >= 18)
        cout << "Puedes jugar el videojuego GTA V" << endl;
      else
        cout << "No puedes jugar GTA V, estas chiquito" << endl;
      break;
    }
    case 'f':
    {
      cout << "Adios, vuelve pronto!!!" << endl;
      break;
    }
    default:
      cout << "La opcion que ingresaste es invalida. Por favor, intentalo de nuevo. =(" << endl;
      break;
    }
  } while (opcionMenu != 'f');


  cout << endl << endl << "______________________" << endl << endl;

  int contador = 10;
  while (contador < 5)
  {
    cout << "El contador vale " << contador << endl;
    contador = contador + 1;
  }


  for (int i = 0; i < edad; i++)
  {
    cout << i + 1 << ") esta es una repeticion" << endl;
  }
  
  
  cout << endl << endl << "______________________" << endl << endl;

  char nombreVideojuego[10];
  nombreVideojuego[0] = 'G';
  nombreVideojuego[1] = 'T';
  nombreVideojuego[2] = 'A';
  nombreVideojuego[3] = ' ';
  nombreVideojuego[4] = 'V';



 ///

}

