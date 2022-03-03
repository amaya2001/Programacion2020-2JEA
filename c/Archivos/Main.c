#include "Archivos.h"

void guardarEmpleados(char path[]) {
	char modo[] = "w";
	FILE* pFile = abrirArchivo(path, modo);
	int numEmpleados = 0;
        printf("Cuantos empleados vas a registrar?: ");
        scanf("%d", &numEmpleados);
	if(pFile!=NULL){
		printf("Guardando archivo empleados \n");
		guardarArchivoFPrint(pFile, numEmpleados);
		fclose(pFile);
	}
	
}


void leerEmpleadosConScanf(char path[]){
	FILE* pFile = abrirArchivo(path, "r");
	if(pFile!=NULL){
		printf("Leyendo archivo\n");
		leerArchivoFScanf(pFile);
		fclose(pFile);
	}
}

void leerEmpleadosConGets(char path[]){
	FILE* pFile = abrirArchivo(path, "r");
	if(pFile!=NULL){
		printf("Leyendo archivo\n");
		leerConFGets(pFile);
		fclose(pFile);
	}
}

void contar(char path[]){
	FILE* pFile = abrirArchivo(path, "r");
        int conteo;
	if(pFile!=NULL){
		printf("Contado lineas\n");
		conteo = contarNumLineas(pFile);
                printf("Total de lineas contadas: %d\n", conteo );
		fclose(pFile);
	}
}


int menu(){
	int opc = 0; 
	//Cambiar el path
	char path[] = "empleadosText.txt";
	do{
		printf("\n1) Guardar archivo de empleados \n");
		printf("2) Leer archivo de empleados con scanf \n");
		printf("3) Leer archivo con Getc \n");
                printf("4) Contar las lineas del archivo \n");
		printf("-1. Salir \n");
		scanf("%d",&opc);

		switch(opc) {
			case GUARDAR: guardarEmpleados(path);
			break;

			case LEERSCANF: leerEmpleadosConScanf(path);
		        break;

			case LEERFGETS: leerEmpleadosConGets(path);
                        break;

                        case 4: contar(path);
                        break;
		}				
	}while (opc != -1);
	return opc;
}

int main()
{
	menu();
	return 0;
}