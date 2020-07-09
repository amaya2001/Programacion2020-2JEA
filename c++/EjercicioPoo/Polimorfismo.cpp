#include <iostream>
#include <stdlib.h>

using namespace std;

class Persona{
    private:
    string nombre;
    int edad;
    public:
    Persona( string, int );
    virtual void mostrar();
};

class Estudiante : public Persona{
    private:
    float notaFinal; 
    public:
    Estudiante( string, int, float );
    void mostrar();
};

Persona::Persona( string _nombre, int _edad ){
    nombre = _nombre;
    edad = _edad;
}

Estudiante::Estudiante( string _nombre, int _edad, float _notaFinal ) : Persona( _nombre, _edad ){
    notaFinal = _notaFinal;
}

void Persona::mostrar(){
    cout<<"Mi nombre es "<<nombre<<", mi edad es "<<edad;
}

void Estudiante::mostrar(){
    Persona::mostrar();
    cout<<", mi nota final es "<<notaFinal;
}

int main(){
    Persona *vector[ 3 ];
    vector[ 0 ] = new Persona( "Juan", 19 );
    vector[ 0 ] -> mostrar();
    vector[ 1 ] = new Estudiante( "Luis", 20, 4.0 );
    cout<<endl;
    vector[ 1 ] -> mostrar();

    return 0;
}