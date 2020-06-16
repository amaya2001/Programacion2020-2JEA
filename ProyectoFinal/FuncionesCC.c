#include "FuncionesCC.h"

Local ** reservarMatriz(int fil, int col){
	int i;

        Local ** pMatriz = new Local* [fil];
	if( pMatriz != NULL ){
        	for( i = 0; i <= fil; i++ ){
                	pMatriz[ i ] = new Local[col];// cada columna de la matriz dinamica va a ser un puntero de tamaño Local 
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

tipoLocal_e tipoDelLocal(){// Enum que retorna el tipo del local.
	tipoLocal_e tipo;

	printf( "De que tipo es su local:\n" );
	printf( "1) Deportivo\n" );
	printf( "2) Entretenimiento\n" );
	printf( "3) Restaurante\n" );
	printf( "4) Moda\n" );
	printf( "Opcion: " );
   	scanf("%d", &tipo);
	try{
		if( tipo  < 0 || tipo > 4 )
			throw "Error: Opcion no puede ser negativo.";
	}catch( const char* dato ){
		cout << dato << endl;
		printf( "Digite nuevamente\n" );
		tipoDelLocal();
	}
	   	return tipo;
}

Local llenarLocal(){
 	Local localTemp;

        fflush( stdin );
	int numero, opinion;
	printf( "Ingrese un nombre del local: " );
	scanf( "%s", &localTemp.nombreLocal ); 
	printf( "Ingrese el piso del local: " );
	scanf( "%d", &localTemp.pisoLocal ); 
	printf( "ingrese el lugar del local: " );
	scanf( "%d", &localTemp.lugarLocal );
	try{
		if( localTemp.pisoLocal  <= 0 || localTemp.lugarLocal <= 0 )
			throw "Error: Piso o lugar no puede ser menor o igual a 0";
	numero = 1000 + rand()%( 10001 + 1000 ); // Genera un numero aleatorio entre 1.000 y 10.000
	localTemp.idLocal = numero; // Adiciona el numero aleatoeio que acabo de crear
	printf( "Su id es: %d", localTemp.idLocal );
	printf( "\n" );
	localTemp.ventasLocal = 0; // Si se acabo de crear un local, es logico decir que sus ventas hasta hora son 0
	printf( "Digite la cantidad de empelados a su disposicion: " );
	scanf( "%d", &localTemp.cantEmpleadosLocal );
		if( localTemp.cantEmpleadosLocal < 0 )
			throw "Error: La cantidad de empleados no puede ser menor a 0";
        opinion = tipoDelLocal();
        localTemp.tipoLocal = opinion;// Adiciona el entero que retorna tipoLocal.  
        switch( opinion ){
        	case DEPORTIVO: printf( "Su local vende cosas deportivas. \n" );
         			break;

         	case JUEGOS: printf( "Su local vende juegos y accesorios relacionados. \n" );
         		     break;

         	case COMIDA: printf( "Su local es un restaurante. \n" );
         		     break;

         	case MODA: printf( "Su local vende ropa y accesorios relacionados. \n" );
        		   break;
	}
	printf( "Digite el total de su inventario: " );
	scanf( "%d", &localTemp.cantInventarioLocal ); // Adiciona un entero que representa el numero total del inventario del local.
		if( localTemp.cantInventarioLocal < 0 )
			throw "Error: La cantidad maxima de empleados no puede ser menor a 0";
	
	return localTemp;
	}catch( const char* dato ){
		cout << dato << endl;
		printf( "Digite nuevamente\n" );
		llenarLocal();
	}
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
	printf( "[Nombre del local: %s, Piso: %d, Lugar: %d, ID: %d, Ventas: %d, Empleados: %d, tipo: %d, Inventario: %d]", pMatriz[ piso ][ lugar ].nombreLocal, pMatriz[ piso ][ lugar ].pisoLocal, pMatriz[ piso ][ lugar ].lugarLocal, pMatriz[ piso ][ lugar ].idLocal, pMatriz[ piso ][ lugar ].ventasLocal, pMatriz[ piso][ lugar ].cantEmpleadosLocal, pMatriz[ piso ][ lugar ].tipoLocal, pMatriz[ piso ][ lugar ].cantInventarioLocal );	
}

void  verificacion( Local ** pMatriz, int fil, int col ){
	int piso, lugar;
	printf( "Ingrese el piso en donde se encuentra el local: " );
	scanf( "%d", &piso );
	printf( "Ingrese el lugar en donde se encuentra el local: " );
	scanf( "%d", &lugar );
	try{
		if( lugar  <= 0 || piso <= 0 )
			throw "Error: Piso o lugar no puede ser menor o igual a 0";
	}catch(const char* dato){
		cout << dato << endl;
		return;
	}
	mostrarLocal( pMatriz, fil, col, piso, lugar ); // Le manda los datos optenidos a la funcion
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
	printf( "Tu compra fue mayor o igual a 250.000, ahora te aremos una prueba para obtener la totalidad de tu compra\n" );
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
	char nombreBusqueda[ 30 ]; // un nombre temporal
	int  i, j, venta, condicion = 250000, retorna;

	printf( "Ingrese el nombre del local: " );
	scanf( "%s", &nombreBusqueda );
	for( i = 0; i <= fil; i++ ){
		for( j = 0; j <= col; j++ ){
			if( strcmp( nombreBusqueda, pMatriz[ i ][ j ].nombreLocal ) == 0 ){ // Compara el nombre temporal con el nombre de local en la posicion i, j
				printf( "Ingrese la venta realizada: " );
				scanf( "%d", &venta );
				try{
					if( venta  <= 0 )
						throw "Error: La venta no puede ser negativo o igual a 0.";
				}catch( const char* dato ){
					cout << dato << endl;
					ingresarVenta( pMatriz, fil, col );
				}
				if( venta >= condicion ){
					retorna = promocion();
						if(retorna == 1){
							pMatriz[ i ][ j ].ventasLocal += 0;// No se le suma nada ya que no gano la promocion
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
	for( i = 0; i <= fil; i++ ){
		for( j = 0; j <= col; j++ ){
			if( strcmp( pMatriz[ i ][ j ].nombreLocal, nomBusqueda ) == 0 ){
				strcpy( pMatriz[ i ][ j].nombreLocal, " " );// Se usa para sobre escribir vacio en el nombre por defecto del local
				pMatriz[ i ][ j ].pisoLocal = 0 ;
				pMatriz[ i ][ j ].lugarLocal = 0;
				pMatriz[ i ][ j ].idLocal = 0;
				pMatriz[ i ][ j ].ventasLocal =  0;
				pMatriz[ i ][ j ].cantEmpleadosLocal = 0;
				pMatriz[ i ][ j ].tipoLocal = 0; 
				pMatriz[ i ][ j ].cantInventarioLocal = 0; 
				printf( "El local: %s fue eliminado correctamente,el espacio quedo libre!\n", nomBusqueda );
				return;
			}
		}
	}
	printf( "No existe!\n" );
}

void seleccion( Local ** pMatriz, int fil, int col ){// Crea un arreglo temporal donde se guarda el id del local para despues ser ordenado con el metodo selección. 
	int i, j, aux = 0, tam = fil * col, min, temp; 
        int lista[ tam ];

	printf( "Datos:\n " );
	for( i = 1; i <= fil; i++ ){
		for( j = 1; j <= col; j++ ){
			printf( "Local: %s, Id: %d.\n", pMatriz[ i ][ j ].nombreLocal, pMatriz[ i ][ j ].idLocal );
			lista[ aux ] = pMatriz[ i ][ j ].idLocal;
			aux++;
		}
	}
 	printf( "\n" );
	for( i = 0; i < tam; i++ ){
		min = i;
		for( j = i + 1; j < tam; j++ ){
			if( lista[ j ] < lista[ min ] ){
				min = j;
			}
		}
		temp = lista[ i ];
		lista[ i ] = lista[ min ];
		lista[ min ] = temp;
	}
	printf( "Id ordenados: " );
	for( i = 0; i <= tam - 1; i++ ){
		printf( "%d ", lista[ i ] );
	}
}

void insercion( Local ** pMatriz, int fil, int col ){// Crea un arreglo temporal donde se guarda el id del local para despues ser ordenado con el metodo interseccion. 
	int i, j, pos, aux, temp = 0, tam = fil * col;
	int lista[ tam ];

	printf( "Datos: \n" );
	for( i = 1; i <= fil; i++ ){
		for( j = 1; j <= col; j++ ){
			printf( "Local: %s, Ventas: %d.\n", pMatriz[ i ][ j ].nombreLocal, pMatriz[ i ][ j ].ventasLocal );
			lista[ temp ] =  pMatriz[ i ][ j ].ventasLocal;
			temp ++;
		}
	}
	for( i = 0; i < tam; i++ ){
	pos = i;
	aux = lista[ i ];

		while( ( pos > 0 ) && ( lista[ pos - 1 ] > aux ) ){
			lista[ pos ] = lista[ pos -1 ];
			pos --;
		} 
		lista[ pos ] = aux;
	}
	printf( "\n" );
	printf( "Ventas ordenadas: " );
	for( i = tam - 1; i >= 0 ; i-- ){
		printf( "%d ", lista[ i ] );
	}
}

void qs( int lista[ ], int limite_izq, int limite_der ){
	int izq, der, temp, mitad;

	izq = limite_izq;	
	der = limite_der;
	mitad = lista[ ( izq + der ) / 2 ];

	do{
		while( lista[ izq ] < mitad && izq < limite_der )izq++;
			while( mitad < lista[ der ] && der > limite_izq )der--;	
				if( izq <= der ){
					temp = lista[ izq ];
					lista[ izq ] = lista[ der ];
					lista[ der ] = temp;
					izq++;
					der--;
				}
	}while( izq <= der );
		if( limite_izq < der ){
			qs( lista, limite_izq, der);
		}
		if( limite_der > izq ){
			qs( lista, izq, limite_der );
		}
}

void quicksort( int lista[ ], int n ){// Crea un arreglo temporal donde se guarda el id del local para despues ser ordenado con el metodo quicksort. 

	qs( lista, 0, n - 1 );
}

void  ArregloMatriz1( Local ** pMatriz, int fil, int col ){
	int i, opc, aux = 0, lista[ fil ];
	printf( "Que fila quieres imprimir: " );
	scanf( "%d", &opc );

	for( i = 1; i <= fil; i++ ){
		lista[ aux ] = pMatriz[ opc ][ i ].cantEmpleadosLocal;
		aux ++;
	}
	int tam = sizeof( lista ) / sizeof( int );
	printf( "Datos: \n" );
	for( i = 1; i <= col; i++ ){
		printf( "Local: %s, Id: %d.\n", pMatriz[ opc ][ i ].nombreLocal, pMatriz[ opc ][ i ].cantEmpleadosLocal );
	}
	quicksort( lista, tam );
	printf( "\n" );
	printf( "Cantidad de empleados ordenados: " );
	for(i = 0; i <= tam - 1; i++ ){
		printf("%d ", lista[ i ]);
	}
}

void merge( int a[ ], int left_low, int left_high, int right_low, int right_high ){
	int lenght = right_high - left_low + 1, temp[ lenght ], left = left_low, right = right_low, i;

	for( i = 0; i < lenght; ++i ){
		if( left > left_high ){
			temp[ i ] = a[ right++ ];
		}else if( right > right_high ){
			temp[ i ] = a[ left++ ];
		}else if( a[ left ] <= a[ right ] ){
			temp[ i ] = a[ left++ ];
		}else{
			temp[ i ] = a[ right++ ];
		}
	}
	for( i = 0; i < lenght; ++i ){
		a[ left_low++ ] = temp[ i];
	}	
}

void ms( int a[ ], int low, int high ){
	if( low >= high ){
		return;
	}else{
		int mid = ( low + high ) / 2;
		ms( a, low, mid );
		ms( a, mid + 1, high );
		merge( a, low, mid, mid + 1, high );
	}
}

void merge_sort( int a[ ], int lenght ){// Recibe un arreglo temporal donde se guarda la cantidad maxima del inventario del local para despues ser ordenado con el metodo mergesort. 
	ms( a, 0, lenght - 1 );
}

void  ArregloMatriz2( Local ** pMatriz, int fil, int col ){
	int i, opc, aux = 0, lista[ col ];
	printf( "Que columna quieres imprimir: " );
	scanf( "%d", &opc );

	for( i = 1; i <= col; i++ ){
		lista[ aux ] = pMatriz[ i ][ opc ].cantInventarioLocal;
		aux ++;
	}
	int tam = sizeof( lista ) / sizeof( int );
	printf( "Datos: \n" );
	for( i = 1; i <= col; i++ ){
		printf( "Local: %s, Id: %d.\n", pMatriz[ i ][ opc ].nombreLocal, pMatriz[ i ][ opc ].cantInventarioLocal );
	}
	merge_sort( lista, tam );
	printf( "\n" );
	printf( "Cantidad de inventario ordenado: " );
	for(i = 0; i <= tam - 1; i++ ){
		printf( "%d ", lista[ i ] );
	}
}

void save( Local ** pMatriz, int numLocales, char * fn ){// Guarda el contenido de la matriz en un archivo binario.  

	FILE * f = fopen(fn, "wb" );
   	fwrite( pMatriz, sizeof( Local ), numLocales, f );
   	fclose( f );
}
Local * load( Local ** pMatriz, int numLocales, char * fn ){// Carga el contenido de la matriz anteriormente guardada en el archivo binario.  

	FILE * f = fopen(fn, "rb" );
   	fread( &pMatriz, sizeof( Local ), numLocales, f );
	return *pMatriz;
   	fclose( f );
}

int mostrarMenu(){
	int opcion;
	
	printf("\n");
	printf("===============================\n");
	printf("   COMERCIO EL MAMUT ROSADO    \n");
	printf("===============================\n");
	printf( "1) Agregar un local\n" );
	printf( "2) Mostrar local\n" );
	printf( "3) Usuario realiza compra\n" );
	printf( "4) Eliminar local\n" );
	printf( "5) Ordenar por id\n" );
	printf( "6) Ordenar por ventas\n" );
	printf( "7) Ordenar por numero  de empleado y fila\n" );
	printf( "8) Ordenar por numero  de inventario y columna\n" );
	printf( "0) Salir\n" );
	printf( "Opcion: " );
	scanf( "%d", &opcion );

	return opcion;
}