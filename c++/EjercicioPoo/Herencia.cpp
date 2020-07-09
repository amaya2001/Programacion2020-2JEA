#include<iostream>
#include<stdlib.h>

using namespace std;

class Persona{
    private:
    string nombre;
    int edad;
    public:
    Persona( string, int );
    void mostrarPersona();
};

class Empleado : public Persona{
    private:
    float sueldo;
    public:
    Empleado( string, int, float );
    void mostrarEmpleado();
};

class Estudiante : public Persona{
    private:
    float notaFinal;
    public:
    Estudiante( string, int, float );
    void mostrarEstudiante();
};

class Universitario : public Estudiante{
    private:
    string carrera;
    public:
    Universitario( string, int, float, string );
    void mostrarUniversitario();
};

Persona::Persona( string _nombre, int _edad ){
    nombre = _nombre;
    edad = _edad;
}

Empleado::Empleado( string _nombre, int _edad, float _sueldo ) : Persona(  _nombre, _edad ){
    sueldo = _sueldo;
}

Estudiante::Estudiante( string _nombre, int _edad, float _notaFinal ) : Persona( _nombre, _edad ){
    notaFinal = _notaFinal;
}

Universitario::Universitario( string _nombre, int _edad, float _notaFinal, string _carrera ) : Estudiante( _nombre, _edad, _notaFinal ){
    carrera = _carrera;
}

void Persona::mostrarPersona(){
    cout<<"Mi nombre es "<<nombre<<", tengo "<<edad;
}

void Empleado::mostrarEmpleado(){
    cout<<endl;
    mostrarPersona();
    cout<<", mi sueldo es "<<sueldo;
}

void Estudiante::mostrarEstudiante(){
    cout<<endl;
    mostrarPersona();
    cout<<", mi nota final es: "<<notaFinal;
}

void Universitario::mostrarUniversitario(){
    mostrarEstudiante();
    cout<<" y mi carrera es: "<<carrera;   
}

int main(){
    Persona p1 = Persona( "Juan", 19 );
    p1.mostrarPersona();
    Empleado e1 = Empleado( "pepe", 30, 12000 );
    e1.mostrarEmpleado();
    Estudiante est1 = Estudiante( "Nicolas", 19, 4.0 );
    est1.mostrarEstudiante();
    Universitario u1 = Universitario( "Dayana", 19, 4.0, "Industrial" );
    u1.mostrarUniversitario();

    return 0;
}