#include "Insercion.h"

int main(){
	int lista[ ] = { 4, 2, 3, 1, 5 };
	int tam = sizeof( lista ) / sizeof( int ), i;

	printf( "Arreglo original: " );
	for( i = 0; i < tam; i++ ){
		printf( "%d ", lista[ i ] );
	}
	Insercion( lista, tam );
	return 0;
}
	