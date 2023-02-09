#include <iostream>
#include <string>

using namespace std;

// cuales son los tipos de datos nativos?
// - char => para caracteres
// - int => para datos tipo entero
// - float => tipo de dato para numeros decimales
// - double => tipo de dato para numeros decimales pero tiene mayor precision que el float
// - bool : boleano => true, false

// Que es un arreglo?
// Es una coleccion de datos con las siguientes caracteristicas
// - Es finito: esto quiere decir que si definimos una cantidad de 100 elementos, esa cantidad no puede cambiar  a lo largo del programa mientras este se este ejecutando.
// - Todos los elementos son del mismo tipo
// - Todos los elementos estan en posiciones contiguas de memoria

int main()
{
  char nombreDeAlumno[10];

  // Para asignar datos a una posicion del arreglo se hace lo siguiente
  nombreDeAlumno[0] = 'R';
  nombreDeAlumno[1] = 'a';
  nombreDeAlumno[2] = 'y';


  // Es esto posible? 
  nombreDeAlumno[3] = 1.32f;
  // si es posible, pero no tiene sentido agregar flotantes a una char
  nombreDeAlumno[4] = 4.32f;

  nombreDeAlumno[5] = 'm';
  nombreDeAlumno[6] = 'u';
  nombreDeAlumno[7] = 'n';
  nombreDeAlumno[8] = 'd';
  nombreDeAlumno[9] = 'o';


  float calificaciones[3];
  calificaciones[0] = 65.1;
  calificaciones[1] = 69.4;
  calificaciones[2] = 99.4;

  // que pasara si asiganmos un dato a un indice mayor a la cantidad de elementos del arreglo
  //calificaciones[5] = 99.4; // no es posible porque no podemos guardar en una posicion que no existe/fue reservada para el arreglo


  nombreDeAlumno[3] = '=';
  nombreDeAlumno[4] = '=';

  // Como puedo imprimir el nombreDeAlumno con el siguiente formato?
  // R.a.y.=.=.m.u.n.d.o

 
  

}
