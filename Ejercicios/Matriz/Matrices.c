#include "Matrices.h"
void llenarMatriz(int matriz [][4],  int fil, int col) {
	int i,j;
	for (i = 0; i < fil; i++) {
		for (j = 0; j < col; j++) {
			printf("Digite el numero en la posicion: [%d], [%d]: ", i, j );
			scanf("%d", &matriz[i][j]);
		}
	}
}

void mostrarMatriz(int matriz [][4],  int fil, int col) {
	int i,j;
	for (i = 0; i < fil; i++) {
		for (j = 0; j < col; j++) {
			printf(" %d ",matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void imprimirAlReves(int matriz [][4] , int fil, int col){
	int i,j;
	for (i = fil-1; i >= 0; i--) {
		for (j = col-1; j >= 0; j--) {
			printf(" %d ",matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void mostrarDiagonal(int matriz[][4], int fil, int col){
	int i,j;
        printf("\nDiagonal: ");
        for(i = 0; i < fil; i++) {
           for(j = 0; j < col; j++) {
              if(matriz[i]==matriz[j]){
	         printf("[%d]", matriz[i][j]);
	      }
  
	   }

        }
}

int esCuadrada(int matriz[][2], int fil, int col){
   int i, j;
   int cuadrada=1;
   if(fil==col){
      return cuadrada;
   }else{
       printf("No es cuadrada");
   }
  
}

void mostrarTranspuesta(int matriz[][2], int fil, int col){
   int i, j;
   for(i=0; i<col;i++){
      for(j=0;j<fil;j++){
         printf(" %d ", matriz[j][i]);    
   }
    printf("\n");
      }
    printf("\n");
}