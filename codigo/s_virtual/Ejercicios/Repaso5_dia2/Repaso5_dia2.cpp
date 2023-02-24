// Repaso5_dia2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Usuario
{
  string Nombre;
  string Apellido;
  int Edad;
};

void ejecutarEjemplosDeArchivosDeTexto()
{
  //--Aqui empieza el ejemplo para escribir datos en un archivo

  //declaramos una variable que servira de referencia para acceder al archivo (file handler)
  fstream file;

  // la funcion open sirve para abrir un archivo
  file.open("ejemplo.txt", ios::out);
  /*
  ios::out ==> para escribir datos en un archivo
  ios::in  ==> para leer datos de un archivo
  */

  /*
  se hacen todas las operaciones de escritura/lectura
  */

  //cout ~ console_output  << "Mensaje";

  file << "Mensajotototototote de prueba 2\n";
  file << "Cadena de pruebas 3";

  //cin ~ console_input >> opcion;

  // Siempre hay que cerrar el archivo al finalizar las operaciones con el mismo
  file.close();

  //--Aqui termina el ejemplo para escribir datos en un archivo

  //--Aqui empieza el ejemplo para leer datos en un archivo

  fstream archivo;
  archivo.open("ejemplo.txt", ios::in);

  string datosDelArchivo;

  cout << "Este es el contendio del la variable _datosDelArchivo_ antes de leer el archivo = " << datosDelArchivo << endl;

  //la funcion getline obtiene toda una cadena de caracteres hasta que encuentra un ENTER (o fin de linea)
  getline(archivo, datosDelArchivo);
  //archivo >> datosDelArchivo;

  cout << "Este es el contendio del la variable _datosDelArchivo_ despues de leer el archivo = " << datosDelArchivo << endl;

  getline(archivo, datosDelArchivo);
  cout << "Este es el contendio del la variable _datosDelArchivo_ despues de volver a leer el archivo = " << datosDelArchivo << endl;

  getline(archivo, datosDelArchivo);
  cout << "Sin lineas que leer, este es el contenido = " << datosDelArchivo << endl;


  archivo.close();
  //--Aqui termina el ejemplo para leer datos en un archivo



  //--Aqui empieza el ejemplo para escribir datos en un archivo con arreglos




  Usuario usuarios[3];
  usuarios[0].Nombre = "Ray";
  usuarios[0].Apellido = "Espinosa";
  usuarios[0].Edad = 31;

  usuarios[1].Nombre = "Roberto";
  usuarios[1].Apellido = "Espinosa";
  usuarios[1].Edad = 25;

  usuarios[2].Nombre = "Angel";
  usuarios[2].Apellido = "Espinosa";
  usuarios[2].Edad = 18;

  /*
  Imprimir con este formato
  Nombre apellido tiene XX anios de edad
  */

  for (int i = 0; i < 3; i++)
  {
    cout << usuarios[i].Nombre << " " << usuarios[i].Apellido << " tiene " << usuarios[i].Edad << " anios de edad\n";
  }


  fstream archivoUsuarios;
  archivoUsuarios.open("usuarios.txt", ios::out);


  for (int i = 0; i < 3; i++)
  {
    archivoUsuarios << usuarios[i].Nombre << " " << usuarios[i].Apellido << " tiene " << usuarios[i].Edad << " anios de edad\n";
  }


  archivoUsuarios.close();

  //--Aqui termina el ejemplo para escribir datos en un archivo con arreglos

  //--Aqui empieza el ejemplo para escribir datos en un archivo con arreglos con diferentes modos

  fstream usersFile;
  usersFile.open("usuarios.txt", ios::out | ios::app);// app => append, agregar mas contenido sin borrar lo anterior

  for (int i = 0; i < 3; i++)
  {
    usersFile << usuarios[i].Nombre << " " << usuarios[i].Apellido << " tiene " << usuarios[i].Edad << " anios de edad\n";
  }

  usersFile.close();

  //--Aqui termina el ejemplo para escribir datos en un archivo con arreglos con diferentes modos

  //--Aqui empieza el ejemplo para validar si un archivo ha sido abierto con exito

  string nombreDeCliente;
  fstream archivito;
  archivito.open("clientes.txt", ios::in);
  //Al leer tenemos que validar que el archivo que tratamos de acceder fue abierto con exito
  if (archivito.is_open())
  {
    archivito >> nombreDeCliente;
    archivito.close();
  }
  else
  {
    cout << "\n\nEl archivo clientes.txt no existe" << endl;
  }


  //--Aqui termina el ejemplo para validar si un archivo ha sido abierto con exito
}

int main()
{

  //ejecutarEjemplosDeArchivosDeTexto();


  int usuariosExistentes = 3;
  Usuario usuarios[10];
  usuarios[0].Nombre = "Ray";
  usuarios[0].Apellido = "Espinosa";
  usuarios[0].Edad = 31;

  usuarios[1].Nombre = "Roberto";
  usuarios[1].Apellido = "Espinosa";
  usuarios[1].Edad = 25;

  usuarios[2].Nombre = "Angel";
  usuarios[2].Apellido = "Espinosa";
  usuarios[2].Edad = 18;


  //--Aqui empieza el ejemplo para escribir datos en un archivo binario

  fstream usuarios2;
  usuarios2.open("usuarios2.bin", ios::out | ios::binary);

  
   //el operador sizeof obtiene el tamaño en bytes de la estructura
  int tamanio = sizeof(Usuario);
  usuarios2.write((char*)(&usuarios[0]), sizeof(Usuario));
  usuarios2.write((char*)(&usuarios[1]), sizeof(Usuario));
  usuarios2.write((char*)(&usuarios[2]), sizeof(Usuario));
  usuarios2.write((char*)(&usuarios[1]), sizeof(Usuario));
  usuarios2.write((char*)(&usuarios[0]), sizeof(Usuario));

  usuarios2.close();
  //--Aqui termina el ejemplo para escribir datos en un archivo binario



  
  //--Aqui empieza el ejemplo para leer datos en un archivo binario

 
  fstream lecturaDeUsuarios;
  lecturaDeUsuarios.open("usuarios2.bin", ios::in | ios::binary);

  //Reservamos memoria para un nuevo usuario
  Usuario* temp = new Usuario;
  //Leemos el archivo y asignamos los datos del archivo en la variable temporal
  lecturaDeUsuarios.read((char*)temp, sizeof(Usuario));
  

  cout << temp->Nombre << " " << temp->Apellido << " tiene " << temp->Edad << " anios de edad\n";


  lecturaDeUsuarios.close();
  //--Aqui termina el ejemplo para leer datos en un archivo binario


  //--Aqui empieza el ejemplo para leer todo el contenido de un archivo binario
  Usuario usuariosLeidos[10];

  lecturaDeUsuarios.open("usuarios2.bin", ios::in | ios::binary | ios::ate); //ate = at the end

  //La funcion tellg nos indica la posicion donde esta el cursor de lectura ( o get cursor)
  int tamanioDeArchivoEnBytes = lecturaDeUsuarios.tellg();
  //HAcemos la division para saber la cantidad de usuarios que estan guardados en el archivo
  int totalUsuarios = tamanioDeArchivoEnBytes / sizeof(Usuario);

  //ya podemos hacer un ciclo para leer cada uno de los registros en el archivo binario
  for (int i = 0; i < totalUsuarios; i++)
  {
    Usuario* temporal = new Usuario;
    //seekg posiciona el cursor de lectura en X posicion
    lecturaDeUsuarios.seekg(i * sizeof(Usuario));
    lecturaDeUsuarios.read((char*)temporal, sizeof(Usuario));
    usuariosLeidos[i] = *temporal;
    //delete temporal;
  }
  lecturaDeUsuarios.close();

  for (int i = 0; i < totalUsuarios; i++)
  {
    cout << usuariosLeidos[i].Nombre << " " << usuariosLeidos[i].Apellido << " tiene " << usuariosLeidos[i].Edad << " anios de edad\n";
  }

 

  //--Aqui termina el ejemplo para leer todo el contenido de un archivo binario
}


