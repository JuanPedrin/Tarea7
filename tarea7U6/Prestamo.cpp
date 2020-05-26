#include "Prestamo.h"
#include "Pelicula.h"
#include "Persona.h"
#include <iostream>
#include <cstring>
using namespace std;

Prestamo::Prestamo()
{

}

Prestamo::Prestamo(int usuario,int pelicula,char fechaInicial[100]){
    this ->usuario=usuario;
    this ->pelicula=pelicula;
    strcpy(this->fechaInicial,fechaInicial);
    this->estatus=1;
}
void Prestamo::devolucion(char fechaFinal[100]){
    strcpy(this->fechaFinal,fechaFinal);
    this->estatus=0;
}
int Prestamo::getUsuario(){
    return this -> usuario;
}
int Prestamo::getPelicula(){
    return this -> pelicula;
}
int Prestamo::getEstatus(){
    return this -> estatus;
}
void Prestamo::toString(){
    cout << "Fecha Inicial: "<< this->fechaInicial<<endl;
    if(this->estatus==1){
        cout << "Estado del prestamo: ocupado"<<endl;
    }else{
        cout << "Estado del prestamo: devuelto"<<endl;
        cout << "Fecha final "<<this->fechaFinal<<endl;
    }
}
