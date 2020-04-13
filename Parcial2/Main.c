#include "FuncionesCC.h"

int main(){
	int opcion, filas = CAP, columnas = CAP;
	setbuf( stdout, NULL );
	Local ** pMatriz = NULL;

	printf( "Ingrese las filas: ");
 	scanf( "%d", &filas );
	printf( "Ingrese las columnas: ");
 	scanf( "%d", &columnas );
	pMatriz = reservarMatriz( filas, columnas );
	srand( time( NULL ) );
   
	do{
  		opcion = mostrarMenu();
  		switch ( opcion ){
			case 1: llenarMatriz( pMatriz, filas, columnas);
				break;

			case 2: verificacion( pMatriz, filas, columnas);
				break;

			case 3: enums();
				break;

			case 4: ingresarVenta( pMatriz, filas, columnas );
				break;
			
			case 5: eliminarLocal( pMatriz, filas, columnas );
				break; 

			case 0: break;						
		}
	}while( opcion != 0 || opcion > 5 );
	
	return 0;
}