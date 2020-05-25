#include <stdio.h>

int main(){

	int lista[ ] = { 4, 2, 3, 1, 5 };
	int i, pos, aux;

	printf( "Arreglo original: " );
	for( i = 0; i < sizeof( lista ) / sizeof( int ); i++ ){
		printf( "%d ", lista[ i ] );
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
	for( i = 0; i < sizeof( lista ) / sizeof( int ); i++ ){
		printf( "%d ", lista[ i ] );
	}
	return 0;
}