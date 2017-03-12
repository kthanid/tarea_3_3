// queue::push/pop
#include "Mascota.h"
#include "Evaluador.h"
#include <iostream>
#include <list>
#include <fstream>
using namespace std;

//Escribe los datos del objeto mascota dado en un archivo binario con el nombre dado en la posicion dada
//Nota: Se deben poder agregar varias mascotas en un solo archivo
void escribir(string nombre_archivo, Mascota*mascota, int posicion)
{
    ofstream out(nombre_archivo.c_str(),ios::in);
    if(!out.is_open()){
        out.open(nombre_archivo.c_str());
    }
    out.seekp(posicion*40);
    out.write((char*)&mascota->edad,4);
    out.write(mascota->nombre.c_str(),36);
out.close();
}

//Devuelve una mascota previamente escrita (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varias mascotas de un solo archivo
Mascota* leer(string nombre_archivo, int posicion)
{
Mascota *m = new Mascota(-1,"");
    ifstream in(nombre_archivo.c_str());
    in.seekg(posicion*40);
    int edad;
    char nombre[36];
    in.read((char*)&edad,4);
    in.read(nombre,36);
    m->edad = edad;
    m->nombre = nombre;
return m;
}

//Devuelve un vector que contenga todas las mascotas previamente escritas (con la funcion escribir()) en un archivo binario con nombre dado
//Nota: El vector debe contener las mascotas ordenadas de acuerdo a la posicion en la que se escribieron
vector<Mascota*> leerTodos(string nombre_archivo)
{
    vector<Mascota*>respuesta;
    ifstream in(nombre_archivo.c_str());
    in.seekg(0,in.end);
    float tamano = in.tellg()/40;
    in.seekg(0);
    int edad;
    char nombre [36];
    for(int i = 0; i < tamano; i++)
    {
        in.read((char*)&edad,4);
        in.read(nombre,36);
        respuesta.push_back(new Mascota(edad, nombre));
    }
    return respuesta;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
