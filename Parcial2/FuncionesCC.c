#include "FuncionesCC.h"

Local ** reservarMatriz(int fil, int col){
	int i;

        Local ** pMatriz = malloc(fil  * sizeof( Local* ));
	if( pMatriz != NULL ){
        	for( i=0; i < fil; i++ ){
                	pMatriz[ i ] = malloc( col * sizeof( Local ) );// cada columna de la matriz dinamica va a ser un puntero de tamaño Local 
			if( pMatriz == NULL ){
				printf( "Error al reservar" );
				break;
			}
                }
        }else {
		printf( "Eror al reservar" );
	}
	return pMatriz;
}

Local llenarLocal(){
	Local localTemp;
        fflush( stdin );
	int numero;

	printf( "Ingrese un nombre del local: " );
	scanf( "%s", &localTemp.nombreLocal ); 
	printf( "Ingrese el piso del local: " );
	scanf( "%d", &localTemp.pisoLocal ); 
	printf( "ingrese el lugar del local: " );
	scanf( "%d", &localTemp.lugarLocal );
	numero = 1000 + rand()%( 10001 + 1000 ); // Genera un numero aleatorio entre 1.000 y 10.000
	localTemp.idLocal = numero; // Adiciono el numero aleatoeio que acabo de crear
	printf( "Su id es: %d", localTemp.idLocal );
	localTemp.ventasLocal = 0; // Si se acaabo de crear un local, es logico decir que sus ventas hasta hora son 0

	return localTemp;
}

void guardarNuevoUsuario( Local ** pMatriz, int fil, int col, int piso, int lugar, Local * pLocal ){
    	pMatriz[ piso ][ lugar ] = *pLocal;
}

void llenarMatriz( Local ** pMatriz, int fil, int col ){
        Local localTemp;
	int piso, lugar;

        localTemp = llenarLocal();  
        piso = localTemp.pisoLocal; 
	lugar = localTemp.lugarLocal; 
	guardarNuevoUsuario( pMatriz, fil, col, piso, lugar, &localTemp );
}

void mostrarLocal( Local ** pMatriz, int fil, int col, int piso, int lugar ){
	if( piso <= fil && lugar <= col ){
	printf( "[Nombre del local: %s, Piso: %d, Lugar: %d, ID: %d, Ventas: %d]", pMatriz[ piso ][ lugar ].nombreLocal, pMatriz[ piso ][ lugar ].pisoLocal, pMatriz[ piso ][ lugar ].lugarLocal, pMatriz[ piso ][ lugar ].idLocal, pMatriz[ piso ][ lugar ].ventasLocal );	
	}
}

void  verificacion( Local ** pMatriz, int fil, int col ){
	int piso, lugar;
	printf( "Ingrese el piso en donde se encuentra el local: " );
	scanf( "%d", &piso );
	printf( "Ingrese el lugar en donde se encuentra el local: " );
	scanf( "%d", &lugar );
	mostrarLocal( pMatriz, fil, col, piso, lugar );
}

	
estadoDeAnimo_e mostrarAnimo(){
	estadoDeAnimo_e animoUsuario;

	printf( "Ingrese un numero del 1 al 4 que refleje su estado de animo: " );
	scanf( "%d", &animoUsuario );

	return animoUsuario;
}

void enums(){
	int opinion; 

	opinion = mostrarAnimo();			
	switch( opinion ){
	case MAL: printf( "Su estado de animo es malo\n" );
		  break;

	case NORMAL: printf( "Su estado de animo es normal \n" );
		     break;

	case BIEN: printf( "Su estado de animo es bueno \n" );
		   break;

	case SUPER: printf( "Su estado de animo es super \n" );
		    break;
	}
}

long recursion( long numero ){
	if( numero < 2 ){
		return numero;
	}else{
		return numero % 2 + ( 10 * recursion( numero / 2 ) );
	}
}

int promocion(){
	long resultado, binario;// Como estas variables va a almacenar enteros grandes, para evitar problemas uso un long que es más grande que un int  
	int numeroAleatorio;	

	numeroAleatorio = 100 + rand()%( 101 + 500 );// Genera un numero aleatorio entre 100 y 500
	printf( "=====================================\n" );
	printf( "          FELICIDADES!!!!!           \n" );
	printf( "=====================================\n" );
	printf( "Tu compra fue mayor o igual a 250.000, ahora te aremos una prueba para obtener el 100 por ciento de tu compra\n" );
	printf( "Te vamos a dar un numero al azar y tines que pasarlo a binario !!\n" );
	printf( "Numero aleatorio: %d\n", numeroAleatorio );
	binario = recursion( numeroAleatorio );
	printf( "Digita el numero en binario: " );
	scanf( "%d", &resultado );
	if( resultado == binario ){
		printf("Ganaste !!!!!!!!!!\n");
		return 1;

	}else{
		printf( "Lo sentimos la resuesta era: %d", binario );
		return 0;	
	}
}

void ingresarVenta( Local ** pMatriz, int fil, int col ){
	char nombreBusqueda[ 30 ];
	int  i, j, venta, condicion = 250000, retorna;

	printf( "Ingrese el nombre del local: " );
	scanf( "%s", &nombreBusqueda );
	for( i = 0; i < fil; i++ ){
		for( j = 0; j < col; j++ ){
			if( strcmp( nombreBusqueda, pMatriz[ i ][ j ].nombreLocal ) == 0 ){
				printf( "Ingrese la venta realizada: " );
				scanf( "%d", &venta );
					if( venta >= condicion ){
						retorna = promocion();
						if(retorna == 1){
							pMatriz[ i ][ j ].ventasLocal += 0;
							return;
						}else{
							pMatriz[ i ][ j ].ventasLocal += venta;
							return;
						}
					}else{
						pMatriz[ i ][ j ].ventasLocal += venta;
						return;
					}
			}
		}
	}
	printf( "No existe\n" );		
}

void eliminarLocal(Local ** pMatriz, int fil, int col){
	char nomBusqueda[ 30 ];
	int i, j;

	printf( "Ingrese el nombre del local a eliminar: " );
	scanf( "%s", &nomBusqueda );
	for( i = 0; i < fil; i++ ){
		for( j = 0; j < col; j++ ){
			if( strcmp( pMatriz[ i ][ j ].nombreLocal, nomBusqueda ) == 0 ){
				strcpy( pMatriz[ i ][ j].nombreLocal, " " );
				pMatriz[ i ][ j ].pisoLocal = 0 ;
				pMatriz[ i ][ j ].lugarLocal = 0;
				pMatriz[ i ][ j ].idLocal = 0;
				pMatriz[ i ][ j ].ventasLocal =  0;
				printf( "El local: %s fue eliminado correctamente,el espacio quedo libre!\n", nomBusqueda );
				return;
			}
		}
	}
	printf("No existe!\n");
}

int mostrarMenu(){
	int opcion;
	
	printf("\n");
	printf("===============================\n");
	printf("   COMERCIO EL MAMUT ROSADO    \n");
	printf("===============================\n");
	printf( "1) Agregar un local\n" );
	printf( "2) Mostrar local\n" );
	printf( "3) Animo de los clientes\n" );
	printf( "4) Usuario realiza compra\n" );
	printf( "5) eliminar local\n");
	printf( "0) Salir\n" );
	printf( "Opcion: " );
	scanf( "%d", &opcion );

	return opcion;
}