#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define CAP 100

typedef struct Local{
	char nombreLocal[ 30 ];
	int pisoLocal, lugarLocal, idLocal;
	long int ventasLocal;
}Local; //  Coloque local para que todo tenga un mismo nombre, ya que me parece engorroso tener Local y Local_e 

typedef enum estadoDeAnimo{
	MAL = 1, NORMAL = 2, BIEN = 3, SUPER = 4 // Se les da un valor numerico porque por defecto los enums empiezan desde 0 y yo nacesito que empiezen desde 1
}estadoDeAnimo_e;

Local ** reservarMatriz(int fil, int col);

Local llenarLocal();

void guardarNuevoLocal( Local ** pMatriz, int fil, int col, int piso, int lugar, Local * pLocal );

void llenarMatriz( Local ** pMatriz, int fil, int col );

void mostrarLocal( Local ** pMatriz, int fil, int col, int piso, int lugar );

void  verificacion( Local ** pMatriz, int fil, int col );

estadoDeAnimo_e mostrarAnimo();

void enums();

long recursion( long numero );

int promocion();

void ingresarVenta( Local ** pMatriz, int fil, int col );

void eliminarLocal(Local ** pMatriz, int fil, int col);

int mostrarMenu();