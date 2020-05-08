#include <stdio.h>
#include <stdlib.h>
#include "maxheap.h"

int menu(){
   int opc;

   printf("================\n"); 
   printf("HOSPITAL TECURO\n");
   printf("================\n");
   printf("1) Ingresar paciente\n");
   printf("2) Atender paciente\n");
   printf("3) Consultar paciente front\n");
   printf("4) Listar pacientes\n");
   printf("5) Borrar todo\n");
   printf("6) Buscar por id\n");
   printf("7) Buscar por nombre nombre\n");
   printf("-1) Salir\n");
   printf("Opcion: ");
   scanf("%d", &opc);
   return opc;
}

int  enums(){
   int opinion; 

   opinion = mostrarAnimo();			
   switch( opinion ){
   case NADA: printf( "No tienes dolor\n" );
   break;

   case POCO: printf( "Tienes poco dolor \n" );
   break;

   case MODERADO: printf( "Tienes un dolor soportable \n" );
   break;

   case MUCHO: printf( "Tienes mucho dolor \n" );
   break;
   }

   return opinion;
}


int main( int argc, char ** argv ){
   if( argc != 2 ){
      printf( "Esta mal!!!!\n" );
      return 0;
   }

   Heap x = createHeap( );
   x.load( &x, argv[ 1 ] );
   int opinion, numero, idBusqueda;
   Persona q;
   char nomTemp[ 20 ];
   srand( time( NULL ) );// El procedimiento de apoya al rand()%

   do{
   opinion = menu();
      switch( opinion ){

         case 1: printf( "Ingrese el nombre del paciente: " );
                 scanf( "%s", q.nombre );
                 numero = 1000 + rand()%( 10001 + 1000 ); // Genera un numero aleatorio entre 1.000 y 10.000
	         q.id = numero; // Adiciono el numero aleatoeio que acabo de crear
                 printf( "Su id es: %d\n", q.id );
		 q.sev = enums();
                 x.put( &x, q ); 
                 break;

         case 2: if( x.empty( &x ) ){
		 printf( "Lo sentimos no hay pacientes =(\n" );
		 break;
		 }
                 q = x.getFront( &x );
                 printf("El paciente: (%s, %d, %d ) fue atendido\n", q.nombre, q.id, q.sev );
                 x.delete( &x );  
                 break;

         case 3: if( x.empty( &x ) ){
		 printf( "Lo sentimos no hay pacientes =(\n" );
		 break;
		 }
                 q = x.getFront( &x );
                 printf( "(%s, %d, %d ) se encuentra en el front\n", q.nombre, q.id, q.sev );
                 break;        

         case 4: x.display( &x );
                 break;

         case 5: printf( "Se estan borrando todos los datos!!\n" );
                 x.clear( &x );
                 break;

         case 6: printf( "Ingrese el id a buscar: " );
                 scanf( "%d", &idBusqueda );
		 x.buscarId( &x, idBusqueda );
                 break;


         case 7: printf( "Ingrese el nombre a buscar: " );
                 scanf( "%s", &nomTemp );
		 x.buscarNombre( &x, nomTemp );
                 break;
      }
   }while( opinion != -1 || opinion > 2 ); 
   x.save( &x, argv[ 1 ] );
   return 0;
}