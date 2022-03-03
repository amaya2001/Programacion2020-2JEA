#include <stdio.h>
#include "arrayStack.h"
#include "arrayQueue.h"

void menu(){
   printf( "\nFinal Exam\n" );
   printf( "==========\n" );
   printf( "1. include\n" );
   printf( "2. eliminate\n" );
   printf( "3. display\n" );
   printf( "4. frolic\n" );
   printf( "0. salir\n" );
   printf( "opc: " );
   return;
}

int main( int argc, char ** argv ){ 
    if( argc != 2 ){ 
       printf( "usage %s [filename]\n", argv[ 0 ] ); 
       return;   
    } 

   int opc, vlr, total = 0, temp;
   Queue sq = createQueue( );
   Stack cq = createStack( );

   sq.load_q( &sq, argv[ 1 ] );
   cq.load_s( &cq, argv[ 1] );
   do{
      menu();
      scanf( "%d", &opc );
      switch( opc ){
         case 1: printf( "ingrese un numero = " );
                 scanf( "%d", &vlr );
                 if( vlr % 2 == 0 ){
                    sq.put( &sq, vlr );
                    total ++;
                 }else{
                    cq.push( &cq, vlr );
                    total ++;
                 }
                 break;

         case 2: printf( "Se esta eliminando el numero\n" );
                 if( total % 2 == 0 ){
                    sq.delete( &sq );
                 }else{
                    cq.pop( &cq );
                 }
                 break;
   
         case 3: sq.display_q( &sq );
                 printf( "\n" );
                 cq.display_s( &cq );
                 break;

         case 4: printf("Cambiando el numero\n");
                 temp = sq.getFront( &sq );
                 sq.delete( &sq );
                 cq.push( &cq, temp );
		 break;

         case 0: break; 
      }
   } while( opc != 0 );
    sq.save_q( &sq, argv[ 1 ] );
    cq.save_s( &cq, argv[ 1 ] ); 
 return 0;
}
