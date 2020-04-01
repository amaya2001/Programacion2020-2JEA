#include "MatricesDinamicas.h"

//Implementar las operaciones del .h


Estudiante ** reservarMatriz(int fil, int col){
   int i;
   Estudiante **pMatriz = malloc(fil*sizeof(Estudiante*));

   if (pMatriz != NULL){
      for(i=0;i<fil;i++){
      pMatriz[i]=malloc (col*sizeof(Estudiante));
         if(pMatriz==NULL){
            printf("Error al reservar");
            break;
         }
         printf("Reservando espacio para la fila %d \n", (i+1));
      }
     }else{
        printf("Error al reservar");
     }
     return pMatriz;
  }

void llenarMatriz(Estudiante ** pMatriz, int fil, int col){
   int i, j;
   Estudiante stTemp; 
   for(i=0;i<fil;i++){
      for(j=0;j<col;j++){
         printf("Ingrese el nombre: ");
         scanf("%s", stTemp.nombre);
         pMatriz[ i ][ j ] = stTemp ; 
      }
   }
}

void mostrarMatriz(Estudiante ** pMatriz, int fil,int col){
   Estudiante stTemp;
   int i, j;
   for(i=0;i<fil;i++){
      for(j=0;j<col;j++){
         stTemp = pMatriz[i][j];
         printf("%s", stTemp.nombre);
      }
      printf("\n");
   }
}