#include "FuncionesCC.h"

int main( int argc, char ** argv ){

	if( argc != 2 ){ // Este condicional es para obligar al usuario a digitar el nombre del archivo.  
      		printf( "Esta mal!!!!\n" );
      		return 0;
   	}
	int opcion, filas = CAP, columnas = CAP;
	setbuf( stdout, NULL ); //Limpia el buffer
	Local ** pMatriz = NULL;// define el prototipo de matriz en NULL

	printf( "Ingrese las filas: ");
 	scanf( "%d", &filas );
	printf( "Ingrese las columnas: ");
 	scanf( "%d", &columnas );
	try{
		if( filas  <= 0 || filas > CAP|| columnas > CAP || columnas <= 0 )
			throw "Error: bad allocation ";
	pMatriz = reservarMatriz( filas, columnas );
	srand( time( NULL ) );// El procedimiento de apoya al rand()%
	do{
  		opcion = mostrarMenu();
		load( pMatriz, filas*columnas, argv[ 1 ]);
  		switch ( opcion ){
			case 1: llenarMatriz( pMatriz, filas, columnas);// Llena la matriz con información proporcinada por el usuario y de manera aleatoria.  
				break;

			case 2: verificacion( pMatriz, filas, columnas);// Emplea un puntero para llenar la matriz con la información almacenada en el struct.
				break;

			case 3: ingresarVenta( pMatriz, filas, columnas );// Solicita el nombre del local para digitar una compra hecha por el usuario.
				break;
			
			case 4: eliminarLocal( pMatriz, filas, columnas );//Solicita el nombre del local para llenar su información con ceros y vacios.
				break; 

			case 5: seleccion( pMatriz, filas, columnas );// Ordena un arreglo por el metodo de seleccion.
				break;

			case 6: insercion( pMatriz, filas, columnas );// Ordena un arreglo por el metodo de seleccion.
				break;
			
			case 7:  ArregloMatriz1( pMatriz, filas, columnas );// Recibe un dato de la matriz, lo asigna a un arreglo y lo manda a una funcion recursiva.  
				break;

			case 8:  ArregloMatriz2( pMatriz, filas, columnas );// Recibe un dato de la matriz, lo asigna a un arreglo y lo manda a una funcion recursiva.  
			break; 

			case 0: break;						
		}
	}while( opcion != 0 || opcion > 5 ); // Las condiciones para que el ciclo continue
	save(pMatriz, filas*columnas, argv[ 1 ]);
	}catch(const char* dato){
		cout << dato << endl;

	}
	return 0;
}