#include "Seleccion.h"

int seleccion( int lista[ ], int tam ){
	int i, j, temp, min;

	for( i = 0; i < tam; i++ ){
		min = i;
		for( j = i + 1; j < tam; j++ ){
			if( lista[ j ] < lista[ min ] ){
				min = j;
			}
		}
		temp = lista[ i ];
		lista[ i ] = lista[ min ];
		lista[ min ] = temp;
	}
	return *lista;
}

