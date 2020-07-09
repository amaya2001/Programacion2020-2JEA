#include "poo.h"

Persona::Persona ( string _nombre, int _edad ){
    nombre = _nombre;
    edad = _edad;
}
 
void Persona::leer(){
    cout<<"soy: "<<nombre<<" y estoy leyendo un libro"<<endl;
}

void Persona::correr(){
    cout<<"soy: "<<nombre<<" y estoy corriendo una maraton"<<endl;
}