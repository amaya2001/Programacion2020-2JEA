#include "Seleccion.h"

int main(){

	int lista[ ]={ 3, 4, 2, 1, 5 };
	int size = sizeof( lista ) / sizeof( int ), i;
	
	printf( "La lista Original: " );
	for( i = 0; i < size; i++ ){
		printf( "%d", lista[ i ] );
		if( i < size - 1 ){
			printf( "," );		
		}
	}

	printf( "\n" );

	seleccion( lista, size );  
	printf( "La lista Ordenada: " );
	for( i = 0; i < size; i++ ){
		printf("%d", lista[ i ]);
		if( i < size - 1 ){
			printf( "," );		
		}
	}

	return 0;
}