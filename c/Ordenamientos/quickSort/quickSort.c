#include "QuickSort.h"

void qs( int lista[ ], int limite_izq, int limite_der ){
	int izq, der, temp, mitad;

	izq = limite_izq;	
	der = limite_der;
	mitad = lista[ ( izq + der ) / 2 ];

	do{
		while( lista[ izq ] < mitad && izq < limite_der )izq++;
			while( mitad < lista[ der ] && der > limite_izq )der--;	
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

void quicksort( int lista[ ], int n ){

	qs( lista, 0, n - 1 );
}