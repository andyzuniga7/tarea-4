#include "Evaluador.h"
#include <fstream>
#include <math.h>
using namespace std;

//Las siguientes funciones escribir y leer ingresan y leen respectivamente un numero ubicado al inicio de un archivo de texto
void escribirNumeroTexto(string nombre_archivo, int num)
{
    ofstream out(nombre_archivo.c_str());
    out<<num<<endl;
    out.close();
} // crea el archivo para escribir & despues escribe el número que se recibe de parámetro

int leerNumeroTexto(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str());
    int num;
    in>>num;
    return num;
} // llama al archivo, lo lee & muestra el número escrito en el

//Las siguientes funciones escribir y leer ingresan y leen respectivamente una cadena ubicada al inicio de un archivo de texto
void escribirStringTexto(string nombre_archivo, string str)
{
    ofstream out(nombre_archivo.c_str());
    out<<str<<endl;
    out.close();
} // crea el archivo para escribir & despues excribe la cadena de texto que se recibe de parámetro

string leerStringTexto(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str());
    string str;
    in>>str;
    return str;
} // llama al archivo, lo lee & muestra la cadena de texto escrita en el

//Las siguientes funciones escribir y leer ingresan y leen respectivamente un numero ubicado al inicio de un archivo binario
void escribirNumeroBinario(string nombre_archivo, int num)
{
        ofstream out(nombre_archivo.c_str());
        out.write((char*)&num,4);
        out.close();
} // crea el archivo para escribir & despues escribe el número que se recibe de parámetro

int leerNumeroBinario(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str());
    int num;
    in.read((char*)&num,4);
    return num;
} // llama al archivo, lo lee & muestra el número escrito en el

//Las siguientes funciones escribir y leer ingresan y leen respectivamente una cadena ubicada al inicio de un archivo binario
void escribirStringBinario(string nombre_archivo, string str)
{
    ofstream out(nombre_archivo.c_str());
    out.write(str.c_str(),10);
    out.close();
} // crea el archivo para escribir & despues escribe el número que se recibe de parámetro

string leerStringBinario(string nombre_archivo)
{
      char* str = new char [10];
      ifstream in(nombre_archivo.c_str());
      in.read(str,10);
      return str;
} // llama al archivo, lo lee & muestra la cadena de texto escrita en el

//Devuelve true si encuentra str (dada) en un archivo dado el nombre
bool existe(string nombre_archivo, string str)
{
    ifstream in(nombre_archivo.c_str());
    char *str0 = new char [10];
    in.read(str0,10);
    if (str0==str)
        return true;
    return false;
} // llama al archivo, lo lee & debería almacenar la palabra & compararla pero al paracer no lo hace

//Devuelve el numero mayor dado el nombre de un archivo binario
int obtenerMayor(string nombre)
{
    int temporal=0;
    int mayor=0;
    ifstream in(nombre.c_str());
    in.seekg(0,ios::end);
    int tamano = in.tellg();
    in.seekg(0,ios::beg);
    for (int i=0;i<tamano;i++)
    {
        in.read((char*)&temporal,4);
        if (temporal>mayor)
            mayor=temporal;
    }
    return mayor;
} // se declaran variable temporal para ir almacenando cada número que se vaya leyendo & mayor para ir almacenando el número mayor..se crea el archivo con el nombre recibido de parámetro..nos vamos al final del archivo para conocer su tamaño..mediante un ciclo for hacemos la comparación de cada número para obtener el mayor & eso retornamos

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
