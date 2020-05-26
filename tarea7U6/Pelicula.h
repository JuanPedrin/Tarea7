#ifndef PELICULA_H
#define PELICULA_H
#include "Persona.h"

class Pelicula
{
    private:
        char titulo[100];
        int annio;
        char genero[100];
        char editorial[100];
        int minutos;
        char director[100];
    public:
        Pelicula();
        Pelicula(char[],int, char[],char[],int,char[]);
        void toString();
        void consultarPeliculas();
};

#endif // PELICULA_H
