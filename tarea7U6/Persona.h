#ifndef PERSONA_H
#define PERSONA_H

class Persona{
    private:
        char nombres[100];
        int edad;

    public:
        Persona();
        Persona(char[],int);
        void toString();
};

#endif // PERSONA_H
