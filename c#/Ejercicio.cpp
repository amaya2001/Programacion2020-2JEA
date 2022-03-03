#include <iostream>
using namespace std;
#define CAP 100

typedef struct Empleado
{
    char nombre[ 30 ];
    float precio;
    int ventas;
    float promedio;

}Empleado;

Empleado masCaro( Empleado arreglo[], int interaciones ){
    Empleado temp = arreglo[ 1 ];

    for( int i = 2; i <= interaciones; i++ ){
        if( arreglo[ i ].precio > temp.precio){
            temp = arreglo[ i ];
        }
    }
    //Tabla de empleados.
    cout<<endl<<"================================"<<endl;
    cout<<"        Tabla de empleados";
    cout<<endl<<"================================"<<endl;

    for( int i = 1; i <= interaciones; i++ ){
        cout<<"Nombre: "<<arreglo[ i ].nombre<<endl;
        cout<<"precio: "<<arreglo[ i ].precio<<endl;
        cout<<"Ventas: "<<arreglo[ i ].ventas<<endl;
        cout<<"Promedio "<<arreglo[ i ].promedio<<endl;
        cout<<endl<<"================================"<<endl;
    }

    return temp;
}

void crearEmpleado( Empleado arreglo[], int iteraciones){
    Empleado caro;

    for( int i = 1; i <= iteraciones; i++ ){
        cout<<endl<<"Empleado #"<<i<<endl;
        cin.ignore();
        cout<<"Nombre del empleado: "; 
        cin.getline( arreglo[ i ].nombre,30 );
        cout<<"Precio unitario: ";
        cin>>arreglo[ i ].precio;
        cout<<"Ventas: ";
        cin>>arreglo[ i ].ventas; 
        arreglo[ i ].promedio = arreglo[ i ].precio * arreglo[ i ].ventas;
        cout<<"Tu importe es de: "<<arreglo[ i ].promedio<<endl;
    }
    caro = masCaro( arreglo, iteraciones );
    cout<<endl<<"El precio mas caro es: "<< caro.precio;   
}

int main(){
    int cantidad;
    Empleado empleados[ CAP ] = { 0 };

    cout<<"Cuantos empleados tiene:";
    cin>>cantidad;
    crearEmpleado( empleados, cantidad );

    return 0;
}