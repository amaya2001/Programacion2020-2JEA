# include <stdio.h>

int seleccion( int lista[], int tam){
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

int main(){

	int lista[ ]={3, 4, 2, 1, 5};
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
