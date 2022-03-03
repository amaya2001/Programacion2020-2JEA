#include "Burbuja.h"

int main(){
	int arreglo[ ] = { 4, 1, 2, 3, 5 };
	int tam = sizeof( arreglo ) / sizeof( int ), i;

	printf("Arreglo original: ");
	for(i=0;i<tam;i++){
		printf("%d ", arreglo[i]);
	}
	printf("\n");
	burbuja( arreglo, tam );
	printf("\n");
	bubbleSort( arreglo, tam );

	return 0;
}