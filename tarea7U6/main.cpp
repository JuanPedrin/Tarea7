#include <iostream>
#include <cstring>
#include "Persona.h"
#include "Pelicula.h"
#include "Prestamo.h"
using namespace std;

Persona registrarUsuario(){
    char nombres[100]; int edad;
    cout << "Ingrese nombre del usuario: ";
    cin >> nombres;
    cout << "edad: ";
    cin >> edad;
    Persona usuario = Persona(nombres,edad);
    return usuario;
}
Pelicula registrarPelicula(){
    char titulo[100]; char director[100]; int annio; char genero[100]; char editorial[100]; int minutos;

    cout << "Ingrese el titulo de la pelicula:"<<endl;
    cin >> titulo;
    cout << "Ingrese nombre del director:"<<endl;
    cin >> director;

    cout << "Ingrese el annio de publicacion:"<<endl;
    cin >> annio;
    cout << "Ingrese el genero del libro:"<<endl;
    cin >> genero;
    cout << "Ingrese la productora:"<<endl;
    cin >> editorial;
    cout << "minutos de duracion: "<<endl;
    cin >> minutos;

    return Pelicula(titulo,annio,genero,editorial,minutos,director);
}
Prestamo registrarPrestamo(int pelicula){
    int usuario;
    char fechaInicial[100];

    cout << "Ingrese el numero de usuario"<<endl;
    cin >> usuario;
    cout << "Ingrese la fecha inicial"<<endl;
    cin >> fechaInicial;


    Prestamo nuevoPrestamo = Prestamo(usuario,pelicula,fechaInicial);
    return nuevoPrestamo;
}
void mostrarPeliculas(Pelicula peliculas[10],int peliculasC){
    for (int i=0; i<peliculasC;i++){
        cout << "Libro "<<i<<" ";
        peliculas[i].consultarPeliculas();
    }
}
void menu(){
    cout <<endl<<"---MENU---" <<endl;
    cout <<"Opcion 1: Usuarios." <<endl;
    cout <<"Opcion 2: Peliculas." <<endl;
    cout <<"Opcion 3: Prestamos(Para realizar prestamos es necesario registrar su usuario)." <<endl;
}
void menuPrestamos(){
    cout << "---Menu de prestamos---"<<endl;
    cout << "1.-Realizar prestamo."<<endl;
    cout << "2.-Devolver pelicula."<<endl;
    cout << "3.-Consultar prestamo."<<endl;
}
void menuUsuarios(){
    cout << "---Menu de Usuarios---"<<endl<<endl;
    cout << "1.-Registrar Usuario."<<endl;
    cout << "2.-Editar datos de usuario."<<endl;
    cout << "3.-Eliminar usuario."<<endl;
    cout << "4.-Consultar datos de usuario"<<endl;
}
void menuPeliculas(){
    cout <<endl<<"---Menu peliculas---" <<endl<<endl;
    cout <<"Opcion 1: Registrar pelicula." <<endl;
    cout <<"Opcion 2: Consultar datos de la pelicula."<<endl;
    cout <<"Opcion 3: Eliminar pelicula." <<endl;
}
int main()
{

    Persona usuarios[10];
    Prestamo prestamos[100];
    bool power=true,t=true;
    int opc = 0, peliculasC=1, num=0,imc=0, usuariosC=1, prestamosC=1,tB,numPeliculas=0;
    char fechaFinal[100];
    cout << "Peliculas Iniciales: ";
    cin >>numPeliculas;
    Pelicula peliculas[numPeliculas];

    while(peliculasC<(numPeliculas+1)){
        cout << "---Registo de peliculas---"<<endl<<endl;
        cout << "Pelicula: "<<peliculasC<<endl;
        peliculas[peliculasC] = registrarPelicula();
        cout << "La pelicula se ha registrado exitosamente con el numero: "<<peliculasC<<endl;
        peliculasC++;
    }

    while (power){
        menu();
        cin >>opc;
        switch(opc){
            case 1:
                menuUsuarios();
                cin >>opc;
                switch(opc){
                    case 1:
                        usuarios[usuariosC] = registrarUsuario();
                        usuariosC++;
                        break;
                    case 2:
                        cout << "Ingrese el numero del usuario"<<endl;
                        cin >> num;
                        usuarios[num].toString();
                        usuarios[num] = registrarUsuario();
                        break;
                    case 3:
                        cout << "Ingrese el numero del usuario"<<endl;
                        cin >> num;
                        usuarios[num].toString();
                        usuarios[num] = Persona();
                        cout<<"Data erased"<<endl;
                        break;
                    case 4:
                        cout << "Ingrese el numero del usuario"<<endl;
                        cin >> num;
                        usuarios[num].toString();
                        break;
                }
                break;
            case 2:
                menuPeliculas();
                cin >>opc;
                switch(opc){
                    case 1:
                        cout << "---Registo de peliculas---"<<endl<<endl;
                        peliculas[peliculasC] = registrarPelicula();
                        cout << "La pelicula se ha registrado exitosamente con el numero: "<<peliculasC<<endl;
                        peliculasC++;
                        break;
                    case 2:
                        cout << "Ingrese el numero de pelicula"<<endl;
                        cin >>num;
                        peliculas[num].toString();
                        break;
                    case 3:
                        cout << "Ingrese el numero de la pelicula"<<endl;
                        cin >>num;
                        peliculas[num] = Pelicula();
                        cout <<endl<< "---Pelicula Eliminada---"<<endl;
                        break;
                }
                break;
            case 3:
                menuPrestamos();
                cin >>opc;
                switch(opc){
                    case 1:
                        mostrarPeliculas(peliculas,peliculasC);
                        cout << "Ingrese el numero del libro"<<endl;
                        cin >>num;
                        t=true;
                        for(int i=0;i<prestamosC;i++){
                            if(num==prestamos[i].getPelicula() && prestamos[i].getEstatus()==1){
                                t=false;
                            }
                        }
                        if(t == true){
                            prestamos[prestamosC]=registrarPrestamo(num);
                            cout << "Prestamo registrado con exito"<<endl;
                            prestamosC++;
                        }else{
                            cout << "La pelicula ya está prestada"<<endl;
                        }
                        break;
                    case 2:
                        cout << "Ingresa el numero del prestamo"<<endl;
                        cin >>num;
                        usuarios[prestamos[num].getUsuario()].toString();
                        tB = prestamos[num].getPelicula();
                        peliculas[tB].toString();
                        prestamos[num].toString();
                        if (prestamos[num].getEstatus()==1){
                            cout << "Ingresa la fecha de devolucion"<<endl;
                            cin >> fechaFinal;
                            prestamos[num].devolucion(fechaFinal);
                            cout << "Pelicula devuelta"<<endl;
                        }else{
                            cout << "El prestamo ha sido finalizado anteriormente"<<endl;
                        }
                        break;
                    case 3:
                        cout << "Ingresa el numero del prestamo"<<endl;
                        cin >>num;
                        usuarios[prestamos[num].getUsuario()].toString();
                        peliculas[prestamos[num].getPelicula()].toString();
                        prestamos[num].toString();
                        break;

                }
        }
    }
    return 0;
}
