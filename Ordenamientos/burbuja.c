#include <stdio.h>

int burbuja(){
	int arreglo[]={4, 1, 2, 3, 5};
	int i, j, aux, tam = sizeof(arreglo)/sizeof(int);

	for(i=0;i<tam;i++){
		for(j=0;j<tam;j++){
			if(arreglo[j]>arreglo[j+1]){
                        	aux = arreglo[j];
				arreglo[j] = arreglo[j+1];
				arreglo[j+1] = aux;
			}
		}
	}
	printf("orden: ");
	for(i=0;i<tam;i++){
		printf("%d ", arreglo[i]);
	}
}

int bubbleSort(){
	int arreglo[] = {3, 6, 1, 5, 7, 4, 2};
	int i, j, aux, tam = sizeof(arreglo)/sizeof(int);

	for(i=1;i<=tam;i++){
		for(j=tam;j>=i;j--){
			if(arreglo[j-1]>arreglo[j]){
				aux = arreglo[j-1];
				arreglo[j-1]=arreglo[j];
				arreglo[j]=aux;
}

}

} 

printf("orden: ");
	for(i=0;i<tam;i++){
		printf("%d ", arreglo[i]);
	}
}

int main(){
	burbuja();
	printf("\n");
	bubbleSort();

	return 0;
}