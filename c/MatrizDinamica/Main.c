#include "MatricesDinamicas.h"

int main()
{
        setbuf(stdout, NULL);
        Estudiante **pMatriz = NULL;
	int filas=2, columnas=4;
	
	pMatriz= reservarMatriz(filas, columnas);
	if(pMatriz!=NULL){
           llenarMatriz(pMatriz, filas, columnas);
           mostrarMatriz(pMatriz, filas, columnas);
           free(pMatriz);
	}else{
		printf("No se pudo reservar espacio en memoria para esta matriz");
	}
	return 0;
}
