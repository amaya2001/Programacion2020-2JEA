#include <iostream>
#include <stdlib.h>
using namespace std;

class Persona {
    private:
    string nombre;
    int edad;
    public:
    Persona( string, int ); // constructor 
    void verPersona();
};

class Estudiante : public Persona{
    private:
    int codigo;
    float notaFinal;
    public:
    Estudiante( string, int, int, float );
    void verEstudiante();
};

Persona::Persona( string _nombre, int _edad ){
    nombre = _nombre;
    edad = _edad;
}

Estudiante::Estudiante( string _nombre, int _edad, int _codigo, float _notaFinal ):Persona( _nombre, _edad ){
    codigo = _codigo;
    notaFinal = _notaFinal;
}

void Persona::verPersona(){
    cout<<"Hola mi nombre es "<<nombre<<" y tengo "<<edad;
}

void Estudiante::verEstudiante(){
    cout<<endl;
    verPersona();
    cout<<" soy estudiante con el codigo: "<<codigo<<" y mi nota final es: "<<notaFinal<<endl;
}

int main(){

    Persona p1 = Persona( "Juan", 19 );
    p1.verPersona();
    Estudiante a1 = Estudiante("Luis", 20, 1200, 3.5);
    a1.verEstudiante();
    return 0;

} 
