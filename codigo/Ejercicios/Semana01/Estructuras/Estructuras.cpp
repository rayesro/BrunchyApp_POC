/// Ejercicios de estructuras
/// Clase de Programacion Avanzada 
/// Lic. Raymundo Espinosa Roque
/// 2023

/*
 Las estructuras o structs son un conjunto de datos (pueden ser de cualquier tipo de dato)
 agrupados bajo un mismo nombre.
 
 Para declarar una estructura, la sintaxis es la siguiente

 struct nombre_struct{  // declaracion de la estructura con su nombre
  int unEnteroRandom;   // Miembro tipo entero llamado unEnteroRandom
  string unaCadena;     // Miembro tipo string llamado unaCadena
 } st1;                 // variable de la estructura llamada st1

 Las estructuras estan compuestas por "N" cantidad de datos que pueden ser de diferente tipo.

 Los datos que componen las estructuras usualmente se les denomina miembros de la estructura.

 La estructura solamente representa el contenedor de datos, por lo que si queremos guardar informacion
 en una estructura, debemos crear una variable de la estructra para guardar ahi los datos que deseemos.

*/

#include <iostream>
#include <string.h>
using namespace std;

void inicializarEstructuras();
void crearEstructurasConArreglos();
void crearArreglosDeEstructuras();
void crearEstructurasAnidadas();

int main()
{
  int opcion = 0;
  
  do
  {
    system("title Ejercicios de estructuras");
    cout << "\n Menu de opciones" << endl;
    cout << " 1) - Inicializar estructuras" << endl;
    cout << " 2) - Estructuras con arreglos como miebros" << endl;
    cout << " 3) - Arreglos de estructuras" << endl;
    cout << " 4) - Estructuras anidadas" << endl;
    cout << " 0) - Salir" << endl;

    cout << " Elige una opcion [0-5]: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
      system("title Ejercicios de estructuras - Como inicializar estructuras");
      inicializarEstructuras();
      break;
    case 2:
      system("title Ejercicios de estructuras - Como crear y manejar estructuras con arreglos");
      crearEstructurasConArreglos();
      break;
    case 3:
      system("title Ejercicios de estructuras - Como manejar arreglos de estructuras");
      crearArreglosDeEstructuras();
      break;
    case 4:
      system("title Ejercicios de estructuras - Como manejar estructuras dentro de estructuras");
      crearEstructurasAnidadas();
      break;
    default:
      break;
    }
    system("pause");
    system("cls");
  } while (opcion != 0);
  return 0;
}


void inicializarEstructuras()
{
  // Esta es un ejemplo usando la forma descrita anteriormente
  // El ejemplo de una Persona funciona porque una Persona puede tener
  // una "N" cantidad de datos que nos pueden interesar, por mencionar algunos:
  // edad, nombre completo, altura, sexo, fecha de nacimiento, etc.
  struct Persona
  {
    int edad;
    string nombre;
    string apellido;
    float alturaEnMetros;
  } Persona1;    // aqui se declara una varible que va a almacenar los datos


  // En el siguiente ejemplo, ya se ha declarado la estructura "persona" en la linea 49.
  // Podemos usar "persona" como si fuera un tipo de dato para declarar mas variables de 
  // dicha estructura, dicho de otra forma, podemos declarar mas personas.

  Persona per1, per2, per3, per4;

  /* Para poder guardar información en los miembros de la estructura,
  * usamos la variable Persona1 que declaramos en la linea 53.
  * La sintaxis es la siguiente
  *
  * nombre_variable.nombre_miembro = "valor";
  * 
  * El punto "." sirve para poder acceder a los miembros de una estructura, ya sea
  * para escribir o leer informacion
  *
  * Usando como ejemplo el nombre de la Persona1, quedaría
  * 
  *   Persona1.nombre = "Raymundo";
  */

  per1.nombre = "Raymundo";
  per2.nombre = "Garza Garcia";
  per3.edad = 50;
  per4.alturaEnMetros = 0.50;

  // o tambien podemos asignar datos capturados por el usuario.

  cout << " Ingresa tu nombre: ";
  cin >> Persona1.nombre;
  cout << " Ingresa tu apellido: ";
  cin >> Persona1.apellido;
  cout << " Ingresa tu edad: ";
  cin >> Persona1.edad;
  cout << " Ingresa tu altura en metros (por ejemplo 1.83): ";
  cin >> Persona1.alturaEnMetros;
  cout << endl << endl << endl;

  // Para imprimir los datos de los miembros, usamos el cout como con cualquier otra variable
  cout << " Los datos de la persona son " <<endl;
  cout << " - Nombre completo........" << Persona1.nombre << " " << Persona1.apellido << endl;
  cout << " - Edad..................." << Persona1.edad<< endl;
  cout << " - Altura................." << Persona1.alturaEnMetros << " metros " << endl;

  cout << endl << endl << endl;

}

void crearEstructurasConArreglos()
{
  /*
  * El manejo de arreglos dentro de estructuras es practicamente el mismo que si fuera un arreglo cualquiera.
  * La diferencia radica en que ahora necesitamos usar una variable de la estructura para poder acceder al miembro arreglo
  */

  struct Calendario
  {
    int anio;
    string meses[12];
    bool esBisiesto;
  };

  //Creamos una variable de la estructura
  Calendario calendario;

  //Para escribir o asignar valores al arreglo meses, usamos la variable y definimos el indice que queremos asginar
  
  calendario.meses[0] = "enero";
  calendario.meses[1] = "febrero";
  calendario.meses[2] = "Marzo";
  calendario.meses[3] = "abril";
  calendario.meses[4] = "mayo";
  calendario.meses[5] = "junio";
  calendario.meses[6] = "agosto";
  calendario.meses[7] = "septiembre";

  // Para leer la informacion del arreglo meses del calendario, podemos usar un ciclo o imprimir de una por una

  cout << " Meses del anio" << endl;
  cout << " - " << calendario.meses[0] << endl;
  cout << " - " << calendario.meses[1] << endl;
  for (int i = 2; i < 8; i++) 
  {
    cout << " - " << calendario.meses[i] << endl; // usamos la varible 1 como indice para imprimir los meses restantes
  }

}

void crearArreglosDeEstructuras()
{
  // Nuestra estructura representa el personaje de un videojuego con algun par de caracteristicas
  struct Personaje
  {
    string nombre;
    int puntosDeAtaque;
    int puntosDeDefensa;
    int puntosDeVida;
  };

  // Nuestro juego puede tener 1 personaje principal, y hasta 10 enemigos.
  Personaje heroe;
  // Ya que las estructuras se pueden manejar como otro tipo de dato, tambien podemos crear arreglos de estructuras simplemente 
  // agregando los corchetes y definiendo la cantidad de elementos que tendra dicho arreglo
  Personaje enemigos[10];

  // Vamos a inicializar los datos de nuestro heroe
  heroe.nombre = "Marco";
  heroe.puntosDeAtaque = 10;
  heroe.puntosDeDefensa = 10;
  heroe.puntosDeVida = 100;

  // El proceso para asignar datos a un elemento del arreglo de estructuras es similar a cuando asignamos datos a arreglos de datos nativos (int, char, float)
  // Necesitamos poner el nombre del arreglo seguido de los corchetes, definir que numero de elemento queremos modificar y poner punto "." seguido del 
  // miembro de la estructura que queremos modificar.
  // Por ejemplo, el primer enemigo es el indice 0 y sus datos se pueden inicializar asi...
  
  enemigos[0].nombre = "General Donald Morden";
  enemigos[0].puntosDeAtaque = 250;
  enemigos[0].puntosDeDefensa = 250;
  enemigos[0].puntosDeVida = 400;

  // Asimismo podemos usar un ciclo para recorrer el arreglo de enemigos y asignar los valores dentro del mismo
  for (int i = 1; i < 10; i++)
  {
    // Usamos la variable "i" como indice, para indicar en que posicion del arreglo queremos guardar los datos.
    // Notese que empezamos el for desde i = 1 porque el elemento 0 ya ha sido asignado.
    enemigos[i].nombre = "Soldado";
    enemigos[i].puntosDeAtaque = 150;
    enemigos[i].puntosDeDefensa = 50;
    enemigos[i].puntosDeVida = 80;
  }
  //Una vez que termine el ciclo, terminaremos con 1 general y 9 soldados

  for (int i = 0; i < 10; i++)
  {
    cout << i + 1<<") Enemigo..." << enemigos[i].nombre ;
    cout << "    ATK = " << enemigos[i].puntosDeAtaque<< " | ";
    cout << "    DEF = " << enemigos[i].puntosDeDefensa << " | ";
    cout << "     HP = " << enemigos[i].puntosDeVida << endl;
  }    
}

void crearEstructurasAnidadas()
{
  // Las estructuras son una coleccion de datos de distinto tipo agrupados bajo un nombre. Dichos datos pueden ser
  // de otra estructura, crea asi una estructura anidada.

  // Supongamos que vamos a programar un juego que tiene personajes y cada personaje puede tener hasta 3 poderes,
  // por lo que procedemos a declarar nuestras estrucutras para el personaje y para el poder.

  // Cada poder tendra un nombre y una cantidad de bonus puntos, este bonus a los puntos de ataque del personaje
  struct Poder
  {
    string nombre;
    int bonusDeAtaque;
    int bonusDeDefensa;
  };

  // El ejemplo del personaje se basa en el ejemplo anterior de "crearArreglosDeEstructuras", pero ademas tiene
  // una cantidad maxima de 3 poderes
  struct Personaje
  {
    string nombre;
    int puntosDeAtaque;
    int puntosDeDefensa;
    Poder poderes[3]; // Aqui definimos un arreglo de estructuras dentro de otra estructura
  };

  // Vamos a crear 2 poderes para despues asignarlos
  Poder superFuerza, ultraDefensa;
  superFuerza.nombre = "Super Fuerza";
  superFuerza.bonusDeAtaque = 100;
  superFuerza.bonusDeDefensa = 0;
  ultraDefensa.nombre = "Ultra Defensa";
  ultraDefensa.bonusDeAtaque = 0;
  ultraDefensa.bonusDeDefensa = 100;
  
  // Vamos a crear un heroe y vamos a asignarle 3 poderes
  Personaje heroe;
  heroe.nombre = "Zemasmas";
  heroe.puntosDeAtaque = 100;
  heroe.puntosDeDefensa = 90;
  // Y vamos a asignar super fuerza y ultra defensa a nuestro heroe.
  // Aqui podemos ver que podemos asignar variables de la estructura previamente inicializadas a nuestro arreglo
  heroe.poderes[0] = superFuerza;
  heroe.poderes[1] = ultraDefensa;

  // Y por ultimo vamos a darle un poder especial.
  // Aqui inicializamos directamente los datos del poder
  heroe.poderes[2].nombre = "Poder especial pequeno";
  heroe.poderes[2].bonusDeAtaque = 5;
  heroe.poderes[2].bonusDeDefensa = 4;


  // Finalmente podemos mostrar los datos de nuestro heroe
  cout << endl << endl;
  cout << " >>> HEROE...." << heroe.nombre << endl;
  cout << " >>>>> ATK...." << heroe.puntosDeAtaque << endl;
  cout << " >>>>> DEF...." << heroe.puntosDeDefensa<< endl;
  //usamos un ciclo para imprimir los datos de los poderes
  for (int i = 0; i < 3; i++)
  {
    cout << " >>>>>>> Poder " << i + 1 << ":........" << heroe.poderes[i].nombre << endl;
    cout << " >>>>>>> BONUS ATK" << i + 1 << ":....." << heroe.poderes[i].bonusDeAtaque << endl;
    cout << " >>>>>>> BONUS DEF" << i + 1 << ":....." << heroe.poderes[i].bonusDeDefensa << endl;
  }

  cout << endl << endl;
  cout << " >>> PODER TOTAL DEL HEROE...." << endl;
  // Recorremos los poderes para sumar los bonus al ataque y defensa del heroe
  for (int i = 0; i < 3; i++)
  {
    heroe.puntosDeAtaque = heroe.puntosDeAtaque + heroe.poderes[i].bonusDeAtaque;
    heroe.puntosDeDefensa = heroe.puntosDeDefensa + heroe.poderes[i].bonusDeDefensa;
  }
  cout << " >>>>> ATK................" << heroe.puntosDeAtaque << endl;
  cout << " >>>>> DEF................" << heroe.puntosDeDefensa;




}


