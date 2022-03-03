#include "Insercion.h"
	
void Insercion(	int lista[ ], int tam ){
	int i, pos, aux;
	
	for( i = 0; i < tam; i++ ){
		pos = i;
		aux = lista[ i ];	
		while( ( pos > 0 ) && ( lista[ pos - 1 ] > aux ) ){
			lista[ pos ] = lista[ pos -1 ];
			pos --;
		} 
		lista[ pos ] = aux;
	}
	printf( "\n" );
	printf( "Arreglo ordenado: " );
	for( i = 0; i < tam; i++ ){
		printf( "%d ", lista[ i ] );
	}
}