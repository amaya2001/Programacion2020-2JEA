#include <stdlib.h>
#include <stdio.h>

typedef struct {
	char nombre_empleado[25];
	int edad;
	float salario;
} empleado_t;

typedef enum Opcion{
	GUARDAR=1, LEERSCANF=2, LEERFGETS=3
}opc_e;

FILE* abrirArchivo(char path[], char modo[]);

void leerArchivoFScanf(FILE* pFile);

void guardarArchivoFPrint(FILE* pFile, int numEmpleados);

void guardarFPuts(FILE * pFile);

void leerConFGets(FILE* pFile);

void leerConFGetc(FILE* pFile);

int contarNumLineas(FILE* pFile);
