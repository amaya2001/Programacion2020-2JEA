#include <iostream>

using namespace std;
#include <stdlib.h>

class Persona{
    private:
    string nombre;
    int edad;
    public:
    Persona( string, int );// constructor 
    void leer();
    void correr();
};
