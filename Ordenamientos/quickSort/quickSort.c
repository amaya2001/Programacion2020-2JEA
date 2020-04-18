#include <stdio.h>

void qs( int lista[ ], int limite_izq, int limite_der ){
	int izq, der, temp, mitad;

	izq = limite_izq;	
	der = limite_der;
	mitad = lista[ ( izq + der ) / 2 ];

	do{
		while( lista[ izq ] < mitad && izq < limite_der )izq++;
			while( mitad < lista[ der ] && der > limite_izq)der--;	
				if( izq <= der ){
					temp = lista[ izq ];
					lista[ izq ] = lista[ der ];
					lista[ der ] = temp;
					izq++;
					der--;
				}
	}while( izq <= der );
		if( limite_izq < der ){
			qs( lista, limite_izq, der);
		}
		if( limite_der > izq ){
			qs( lista, izq, limite_der );
		}
}

void quicksort(int lista[ ], int n){

	qs( lista, 0, n - 1 );
}

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