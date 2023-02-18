// Repaso4_dia1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

void ejecutarEjemploDeManejoDeArreglosComoPunteros()
{
  int puntos[] = { 15,30,45,60,75,90,100 }; // 7 elementos

  cout << "Imprimendo el 1er elemento con indice....." << puntos[0] << endl;
  cout << "Imprimendo el 1er elemento con puntero....." << *puntos << endl;
  cout << "Imprimendo el 2do elemento con puntero....." << *(puntos + 1) << endl;
  cout << "Imprimendo el ?? elemento con puntero....." << *(puntos + 6) << endl;
  
  cout << "Imprimendo el ?? elemento con puntero....." << *(puntos + 7) << endl;
  cout << "Imprimendo el ?? elemento con puntero....." << *(puntos - 1) << endl;
}

void ejecutarEjemploDeAritmeticaDePuntero()
{
  char mensaje[] = "Este es un ejemplo de aritmetica de punteros";

  cout << "=============================================" << endl;
  cout << mensaje << endl ;
  cout << "=============================================" << endl;

  char* ptr = &mensaje[0];
  *ptr = '3';

  cout << mensaje << endl;
  cout << "=============================================" << endl;

  ptr++; // ptr = ptr + 1;
  *ptr = '5';

  cout << mensaje << endl;
  cout << "=============================================" << endl;

  ptr += 3;
  *ptr = *(ptr - 1);

  cout << mensaje << endl;
  cout << "=============================================" << endl;

  for (ptr = &mensaje[0]; *ptr != ' '; ptr++)
  {
    *ptr = '$';
  }

  cout << mensaje << endl;
  cout << "=============================================" << endl;

  for (ptr = &mensaje[1]; *ptr != 's'; ptr+=2)
  {
    *ptr = '@';
  }

  cout << mensaje << endl;
  cout << "=============================================" << endl;

  int ultimaPosicion = strlen(mensaje) - 1;
  ptr = &mensaje[ultimaPosicion];

  for (int i = ultimaPosicion; i > 0; i--, ptr--)
  {
    *ptr = 65 + 26 - i; 
  }

  cout << mensaje << endl;
  cout << "=============================================" << endl;


  cin.get();
  cin.ignore();

}

// paso por copia o paso por valor
void calcularPromedio(float promedio, float cal1, float cal2, float cal3)
{
  promedio = cal1 + cal2 + cal3;
  promedio /= 3;
}

// paso por referencia
void calcularPromedio(float* promedio, float cal1, float cal2, float cal3)
{
  *promedio = cal1 + cal2 + cal3;
  *promedio /= 3;
}

float calcularPromedio(float c1, float c2, float c3)
{
  float promedio = c1 + c2 + c3;
  promedio /= 3;
  return promedio;
}

float calcularPromedioYObtenerCalifMax(float* maxCal,float c1, float c2, float c3)
{
  float promedio = c1 + c2 + c3;
  promedio /= 3;

  if (c1 > c2 && c1 > c3)
    *maxCal = c1;
  else if (c2 > c1 && c2 > c3)
    *maxCal = c2;
  else if (c3 > c1 && c3 > c2)
    *maxCal = c3;

  return promedio;
}

int main()
{
  //ejecutarEjemploDeManejoDeArreglosComoPunteros();
  //ejecutarEjemploDeAritmeticaDePuntero();
  /*float prom = 0;
  calcularPromedio(&prom, 100, 100, 100);*/
  float califMaxima = 0;
  float prom = calcularPromedioYObtenerCalifMax(&califMaxima, 95.5, 96.35, 90.1);
  cout << "Promedio: " << prom << endl;
  cout << "Calificacion maxima:" << califMaxima<< endl;


  int edades[10];

  int* edadesDinamico = new int[10];
  for (int i = 0; i < 10; i++)
  {
    edadesDinamico[i] = (i + 1) * 10;
  }

  for (int i = 0; i < 10; i++)
  {
    cout << edadesDinamico[i] << endl;
  }

  delete edadesDinamico;
  edadesDinamico = new int[100];
  for (int i = 0; i < 100; i++)
  {
    edadesDinamico[i] = (i + 1) * 6;
  }
  for (int i = 0; i < 100; i++)
  {
    cout << edadesDinamico[i] << endl;
  }

  cout << endl << endl << endl;
  delete edadesDinamico;
}
