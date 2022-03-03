#include "Matrices.h"

void mostrarMenu() {
	int opcion = 0;
	int filas = 4, columnas=4;
        int fil = 2, col = 2; 
	int matriz[filas][columnas];
	int matrizListInic[4][4] = { { 1, 2 }, { 3, 4},{6,7},{1,2} };
	int matrizCero[4][4] = { {1,2,7,6}, { 5,8,9,6}, {1,6,4,8}, {9,5,6,7} };
        int matrizDiagonal[4][4] ={ {5, 2, 4, 2}, {1,7,8,6},{8,3,7,4},{8,9,7,3} };
        int matrizCuadrada[2][2] = { { 1, 2 }, { 3, 4} };
        int matrizTranspuesta[2][2] = { { 5 ,6 }, { 7, 8 } };
        int matrizFinal[2][2]={ { 9, 8 }, { 5, 6 } };
      
	do {
		printf(" \nOpciones para matrices \n\n");
		printf("1. LLenar matriz\n");
		printf("2. Mostrar matriz\n");
		printf("3. Imprimir al reves\n");
		printf("4. Imprimir diagonal\n");
                printf("5. Es cuadrada\n");
                printf("6. Transpuesta\n");
		printf("-1. Salir\n\n");
		printf(" Opc: ");
		scanf("%d", &opcion);
		switch (opcion) {
			case 1:
				llenarMatriz(matriz,filas,columnas);
				break;
			case 2:
				mostrarMatriz(matrizCero,filas,columnas);
				break;
			case 3:
				imprimirAlReves(matrizCero,filas,columnas);
				break;

                        case 4:
                               mostrarDiagonal(matrizDiagonal,filas,columnas);
                               break;
                        case 5:
                               esCuadrada(matrizCuadrada,fil,col);
                               if(esCuadrada){
                                  printf("Es cuadrada");
                               }
                               break;

                        case 6:
                               mostrarTranspuesta(matrizTranspuesta,fil,col);
                               break;
                        
    
		
		}
		//Cuando el usuario ingrese -1 se terminará el while y se terminará el menu
	} while(opcion!=-1);
}



int main()
{
	//Menu que muestra las opciones disponibles
	mostrarMenu ();
	return 0;
}