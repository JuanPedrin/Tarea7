#include <iostream>
#include <cstring>
#include "Persona.h"
using namespace std;

Persona::Persona(){

}

Persona::Persona(char nombres[100],int edad){
    strcpy(this->nombres,nombres);
    this->edad=edad;

}

void Persona::toString(){
    cout <<endl<< "---Informacion del autor---"<<endl;
    cout << "Nombre: "<< this->nombres<<endl;
    cout << "Edad: "<<this->edad<<endl;
}
