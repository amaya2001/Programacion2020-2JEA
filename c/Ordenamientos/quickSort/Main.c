#include "QuickSort.h"

int main(){
	int lista[ ] = { 100, 56, 0, 1, -45, 2, 46, 5, 9, 6, 67, 23, 5 };
	int size = sizeof( lista ) / sizeof( int ), i;

	printf( "Lista desordenada: " );    
	for( i=0; i < size; i++ ){
		printf( "%d", lista[ i ] );
		if( i < size - 1 ){
			printf( "," );
		}
	}
		
	printf("\n");

	quicksort( lista,size );
	printf( "Lista ordenada: " );
	for( i = 0; i < size; i++ ){
		printf( "%d", lista[ i ] );
		if( i < size - 1 ){
			printf(",");
		}
	}
	return 0;
}