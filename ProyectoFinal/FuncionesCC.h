#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define CAP 100

typedef struct Local{
	char nombreLocal[ 30 ];
	int pisoLocal;
	int lugarLocal; 
	int idLocal;
	long ventasLocal;
	int cantEmpleadosLocal;
	int tipoLocal;// Enums que retorna un entero.
	int cantInventarioLocal;
	
}Local;//  Coloque local para que todo tenga un mismo nombre, ya que me parece engorroso tener Local y Local_e 

typedef enum tipoLocal{
	DEPORTIVO = 1, JUEGOS = 2, COMIDA = 3, MODA = 4 // Se les da un valor numerico porque por defecto los enums empiezan desde 0 y yo nacesito que empiezen desde 1
}tipoLocal_e;

Local ** reservarMatriz(int fil, int col);

Local llenarLocal();

void guardarNuevoUsuario( Local ** pMatriz, int fil, int col, int piso, int lugar, Local * pLocal );

void llenarMatriz( Local ** pMatriz, int fil, int col );

void mostrarLocal( Local ** pMatriz, int fil, int col, int piso, int lugar );

void  verificacion( Local ** pMatriz, int fil, int col );

long recursion( long numero );

int promocion();

void ingresarVenta( Local ** pMatriz, int fil, int col );

void eliminarLocal(Local ** pMatriz, int fil, int col);

void seleccion(Local ** pMatriz, int fil, int col);

void insercion( Local ** pMatriz, int fil, int col );

void qs( int lista[ ], int limite_izq, int limite_der );

void quicksort( int lista[ ], int n );

void ArregloMatriz1( Local ** pMatriz, int fil, int col );

tipoLocal_e tipoDelLocal();

void merge(int a[], int left_low, int left_high, int right_low, int right_high);

void ms(int a[], int low, int high);

void merge_sort(int a[], int lenght);

void  ArregloMatriz2( Local ** pMatriz, int fil, int col );

void save( Local ** pMatriz, int numLocales, char * fn );

void load( Local ** pMatriz, int numLocales, char * fn );

int mostrarMenu();