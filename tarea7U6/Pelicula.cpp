#include "Pelicula.h"
#include "Persona.h"
#include <iostream>
#include <cstring>
using namespace std;
Pelicula::Pelicula()
{

}
Pelicula::Pelicula(char titulo[100],int annio,char genero[100],char editorial[100],int minutos, char director[100])
{
    strcpy(this->titulo,titulo);
    this->annio=annio;
    strcpy(this->genero,genero);
    strcpy(this->editorial,editorial);
    this->minutos=minutos;
    strcpy(this->director,director);
}

void Pelicula::toString(){
    cout <<endl<< "---Datos de la pelicula---"<<endl<<endl;
    cout << "Titulo "<< this->titulo <<endl;
    cout << "Director "<< this ->director<<endl;
    cout << "annio: "<< this->annio <<endl;
    cout << "Genero: "<< this-> genero <<endl;
    cout << "Productora: "<< this-> editorial <<endl;
    cout << "Duracion: "<< this->minutos <<endl;
}
void Pelicula::consultarPeliculas(){
    cout << "Titulo "<< this->titulo <<endl;
}
