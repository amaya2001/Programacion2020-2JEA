#include "Version1.h"

int main(void){
   int opcion, posicion = 0, mesBuscar, mes, resultado, i, mesEnum, contador;
   Persona arreglo[ CAP ];
   // NO estas usando el contador para nada
   do{
      opcion = menu();
      switch (opcion){
         case 1: printf("Digite su nombre: ");
                 scanf("%s", arreglo[ posicion].nombre );
                 printf("Digite el mes: ");
                 scanf("%d", &arreglo[ posicion ].mes);
                 printf("Digite el dia: ");
                 scanf("%d", &arreglo[ posicion ].dia);
                 printf("Digite el anio: ");
                 scanf("%d", &arreglo[ posicion++ ].anio);
                 break;

         case 2: printf("Digite mes a buscar\n ");
                 scanf("%d", &mesBuscar);
                 for (i = 0; i < posicion; i++){
                       if(mesBuscar==arreglo[ i ].mes){
                          printf("[ %s ] cumple en %d \n", arreglo[ i ].nombre, arreglo[ i ].mes);
                       }
                 }
                 break;

         case 3: printf("Digite el # del mes: ");
                 scanf("%d", &mes);
                 if(mes == 2){
                    resultado = contarMes(28);
                 }
                 else {
                    resultado = contarMes(30);
                 }
                 printf("Cantidad de dias pares del mes:[ %d ] : %d\n", mes, resultado);
                 break;

         case 4: //un condicional, un ciclo y enums. 
                 printf("Escriba el numero de un mes para saber que mes es: ");
                 scanf("%d", &mesEnum);
                 for (i = ENE; i <= DIC; i++){
                    if(i == mesEnum){
                       printf("%s \n", getMes(mesEnum));
                       break; 
                    }
                 }
                 break;
              
         case 5: for(i = 0; i < posicion; i++){
	            printf("[ %s, %d, %d, %d ]", arreglo[ i ].nombre, arreglo[ i ].dia, arreglo[ i ].mes, arreglo[ i ].anio);
                 }   
                 break;            

         case 0: break;
      }
     
   }while(opcion != 0);

   return 0;
}