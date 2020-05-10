#include <stdio.h>
#include <stdlib.h>
#include <time.h>// Uso time.h en el rand() para los datos aleatorios, para el __DATE__ y __TIME__.
#define CAP 100000 // La capacidad que tienen todos los arreglos declarada como constante para un rapido cambio de valor.

	time_t start, end;


int menu(){// Este menu sirve para que el usuario elija el tipo de dato de desea, de forma aleatoria  o en orden.
	int dato;

	printf( "Que clase de datos desea:" );
        printf( "\n" );
	printf( "1) Al azar\n" );
	printf( "2) Ordenados\n" );
	printf( "Opcion: " );
	scanf( "%d", &dato );

	return dato;
}

//Aqui empiezan los algoritmos de ordenamiento.

int burbuja( int arreglo[ ], int tam ){
	int i, j, aux, intercambios = 0, comparaciones = 0;

	for( i = 0; i < tam; i++ ){
		for( j = 0; j < tam; j++ ){
			if( arreglo[ j ] > arreglo[ j + 1 ] ){
				comparaciones ++;
                        	aux = arreglo[ j ];
				intercambios ++;
				arreglo[ j ] = arreglo[ j + 1 ];
				intercambios ++;
				arreglo[ j + 1 ] = aux;
				intercambios ++;
			}
		}
	}
	printf( "Total de comparaciones: %d\n", comparaciones );
	printf( "Total de intercambios: %d\n", intercambios );

	return *arreglo;
}

int bubblesort(int arreglo[ ], int tam){
	int i, j, aux, intercambios = 0, comparaciones = 0;

	for( i = 1; i <= tam; i++ ){
		for( j = tam; j >= i; j-- ){
			if( arreglo[ j - 1 ] > arreglo[ j ] ){
				comparaciones ++;
				aux = arreglo[ j - 1 ];
				intercambios ++;
				arreglo[ j - 1 ] = arreglo[ j ];
				intercambios ++;
				arreglo[ j ] = aux;
				intercambios ++;
			}

		}

	} 
	printf( "Total de comparaciones: %d\n", comparaciones );
	printf( "Total de intercambios: %d\n", intercambios );

	return *arreglo;
}

int seleccion( int lista[ ], int tam){
	int i, j, temp, min, intercambios = 0, comparaciones = 0;

	for( i = 0; i < tam; i++ ){
		min = i;
		for( j = i + 1; j < tam; j++ ){
			if( lista[ j ] < lista[ min ] ){
				comparaciones ++;
				min = j;
				intercambios ++;
			}
		}
		temp = lista[ i ];
		intercambios ++;
		lista[ i ] = lista[ min ];
		intercambios ++;
		lista[ min ] = temp;
		intercambios ++;
	}
	printf( "Total de comparaciones: %d\n", comparaciones );
	printf( "Total de intercambios: %d\n", intercambios );

	return *lista;
}

void qs( int lista[ ], int limite_izq, int limite_der ){
	int izq, der, temp, mitad, intercambios = 0, comparaciones = 0;

	izq = limite_izq;	
	der = limite_der;
	mitad = lista[ ( izq + der ) / 2 ];

	do{
		while( lista[ izq ] < mitad && izq < limite_der )izq++;
			while( mitad < lista[ der ] && der > limite_izq )der--;	
				if( izq <= der ){
                                	comparaciones ++;
					temp = lista[ izq ];
					intercambios ++;
					lista[ izq ] = lista[ der ];
					intercambios ++;
					lista[ der ] = temp;
					intercambios ++;
					izq++;
					der--;
				}
	}while( izq <= der );
		if( limite_izq < der ){
			comparaciones ++;
			qs( lista, limite_izq, der);
		}
		if( limite_der > izq ){
			comparaciones ++;
			qs( lista, izq, limite_der );
		}
}

void quicksort( int lista[ ], int n ){

	qs( lista, 0, n - 1 );
}

FILE* abrirArchivo( char path[], char modo[] ) {
	if ( path != NULL ) {
		FILE* pFile = fopen( path, modo );
		return pFile;
	}
	return NULL;
}

void guardarArregloEnterosArchivoBinario( FILE *pFile, int tamArreglo ) {
	int arregloEntero[ tamArreglo ];
	int i, x, resultado;
	resultado = menu();
	printf( "Guardando archivo binario con los datos seleccionados\n" );
	if( resultado == 1 ){
	for( i = 0; i < tamArreglo; i++ ){
		x = 1 + rand()%( ( CAP + 1 ) + 1 ); // Genera un numero aleatorio entre 1 y CAP (La capacidad maxima establecida).
		arregloEntero[ i ] = x; // Se asignan los numeros aleatorios en cada lugar del arreglo.
		}
	}
	if( resultado == 2 ){
		for( i = 0; i < tamArreglo; i++ ){ 
		arregloEntero[ i ] = i + 1;// Se asignan los numeros (En orden del menor al mayor) en cada lugar del arreglo.
		}
	}
	fwrite( arregloEntero, sizeof( int ), tamArreglo, pFile );
	fclose( pFile );
}

void leerArregloEnterosArchivoBinario(FILE *pFileDatos, FILE *pFileOrdenados, int tamArreglo) {
	int arregloEnteroDatos[tamArreglo];
	int arregloOrdenadosSeleccion[tamArreglo];
	int arregloOrdenadosQuickSort[tamArreglo];
        int arregloOrdenadosBurbuja[tamArreglo];
	int arregloOrdenadosBubbleSort[tamArreglo];
	
	printf( "Leyendo los datos\n" );
	fread(arregloEnteroDatos, sizeof( int ), tamArreglo, pFileDatos);
 	*arregloOrdenadosQuickSort = *arregloEnteroDatos ;
	printf( "Se inicio el metodo de seleccion\n" );
	start = time( NULL );
        *arregloOrdenadosSeleccion = seleccion( arregloEnteroDatos, tamArreglo / sizeof( int ) );
        end = time( NULL );
        printf( "Tiempo de ejecucion: %.2f segundos\n", difftime( end, start ) );
	printf( "Se inicio el metodo de burbuja\n" );
	start = time( NULL );
        *arregloOrdenadosBurbuja = burbuja( arregloEnteroDatos, tamArreglo / sizeof( int ) );
	end = time( NULL );
	printf( "Tiempo de ejecucion: %.2f segundos\n", difftime( end, start ) );
	printf( "Se inicio el metodo de bubblesort\n" );
	start = time( NULL );
	*arregloOrdenadosBubbleSort = bubblesort( arregloEnteroDatos, tamArreglo / sizeof( int ) );
	end = time( NULL );
	printf( "Tiempo de ejecucion: %.2f segundos\n", difftime( end, start ) );
	//Se asigna a cada arreglo temporal los datos generados en guardarArregloEnterosArchivoBinario, y se le asigna lo que retorne cada funcion.  
        fwrite( arregloOrdenadosSeleccion, sizeof( int ), tamArreglo, pFileOrdenados );
	printf( "Se inicio el metodo de quicksort\n" );
	start = time( NULL );
        quicksort( arregloOrdenadosQuickSort, tamArreglo/sizeof( int ) );
	end = time( NULL );
	printf( "Tiempo de ejecucion: %.2f segundos\n", difftime( end, start ) );
        fwrite( arregloOrdenadosQuickSort, sizeof( int ), tamArreglo, pFileOrdenados );
        fwrite( arregloOrdenadosBurbuja, sizeof( int ), tamArreglo, pFileOrdenados );
	fwrite( arregloOrdenadosBubbleSort, sizeof( int ), tamArreglo, pFileOrdenados );
	//Cada arreglo ordenado se escribe en el archivo de datosOrdenadosBinario.
	fclose( pFileDatos );
        fclose( pFileOrdenados );
	//Cada que se abre un archivo se debe cerrar.
}

int main(){
    char pathDatos[ ] = "GeneradorDeDatosBinarios";
    char pathOrdenados[ ] = "DatosOrdenadosBinarios";
    char modo[ ] = "w";
    FILE* pFileDatos = abrirArchivo( pathDatos, modo );
    FILE* pFileOrdenados = abrirArchivo( pathOrdenados, modo );
    srand( time( NULL ) );// El procedimiento de apoya al rand()%

	if( pFileDatos != NULL ) {
		guardarArregloEnterosArchivoBinario(pFileDatos, CAP);// Se le manda el nombre del archivo junto a la capacidad maxima
	}else{
		printf( "No se pudo abrir correctamente el archivo\n" );
	}
	
	pFileDatos = abrirArchivo( pathDatos, "r" );
	if( pFileDatos != NULL ) {
			leerArregloEnterosArchivoBinario( pFileDatos, pFileOrdenados, CAP );
	}else{
		printf( "No se pudo abrir correctamente el archivo\n" );
	}
}