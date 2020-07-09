#include "MergeSort.h"

int main(){
	int lista[] = { 2, 6, 4, 7, 1, 5, 3 };
	int tam = sizeof( lista )/sizeof( int ), i;

	printf( "Arreglo original: " );
	for( i = 0; i < tam; i++ ){
		printf( "%d ", lista[ i ] );
	}
	merge_sort( lista, tam );
	printf( "\nArreglo ordenado: " );
	for( i = 0; i < tam; i++ ){
		printf( "%d ", lista[ i ] );
	}		
		
	return 0;
}