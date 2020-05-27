#include "Burbuja.h"

int burbuja( int arreglo[ ], int tam ){
	int i, j, aux;

	for( i = 0; i < tam; i++ ){
		for( j = 0; j < tam; j++ ){
			if( arreglo[ j ] > arreglo[ j + 1 ] ){
                        	aux = arreglo[ j ];
				arreglo[ j ] = arreglo[ j + 1 ];
				arreglo[ j + 1 ] = aux;
			}
		}
	}
	printf( "Burbuja: " );
	for( i = 0; i < tam; i++ ){
		printf( "%d ", arreglo[ i ] );
	}
}

int bubbleSort( int arreglo[ ], int tam ){
	int i, j, aux;

	for( i = 1; i <= tam; i++ ){
		for( j = tam; j >= i; j-- ){
			if( arreglo[ j - 1 ] > arreglo[ j ] ){
				aux = arreglo[ j - 1 ];
				arreglo[ j - 1 ] = arreglo[ j ];
				arreglo[ j ] = aux;
			}

		}

	} 
	printf( "BubbleSort: " );
	for( i = 0; i < tam; i++ ){
		printf( "%d ", arreglo[ i ] );
	}
}
