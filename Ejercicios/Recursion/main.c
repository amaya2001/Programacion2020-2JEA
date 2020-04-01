#include <stdio.h>
#include "recursion.h"

int main(){
   int op, numero1, numero2, multiplicacion, conteo, suma, conteoRango1, conteoRango2, sumaRango1, sumaRango2;
  
   do{
      op = menu();
      switch(op){
      case 1 : fflush(stdin);
               lista5(5);
               break;

      case 2 : printf("\nDigite dos numeros: ");
               scanf("%d %d", &numero1, &numero2);
               multiplicacion = multi(numero1, numero2);
               printf("La multiplicacion en %d y %d es: %d\n", numero1, numero2, multiplicacion);
               break;

      case 3 : conteo = contarPares(10);
               printf("El conteo de los numeros pares entre el 0 y el 10 es: %d\n", conteo);
               break;

      case 4 : suma = sumarPares(10);
               printf("La suma de los nummeros pares entre el 0 y el 10 es: %d\n", suma);
               break;

      case 5 : printf("Digite el rango a contar: ");
               scanf("%d %d", &numero1, &numero2);
               if(numero1 > numero2){
                  conteoRango1 = rangoConteo(numero1,numero2);
                  printf("Conteo de pares entre %d y %d: %d\n", numero1, numero2, conteoRango1);
               }
               else if(numero2 > numero1){
                  conteoRango2 = rangoConteo(numero1,numero2);
                  printf("Conteo de pares entre %d y %d: %d\n", numero1, numero2, conteoRango2);
               }
               break;

      case 6 : printf("Digite el rango a sumar: ");
               scanf("%d %d", &numero1, &numero2);
               if(numero1 > numero2){
                  sumaRango1 = sumarParesRango(numero1,numero2);
                  printf("Suma de pares entre %d y %d: %d\n", numero1, numero2, sumaRango1);
               }
               else if(numero2 > numero1){
                  sumaRango2 = sumarParesRango(numero1,numero2);
                  printf("Suma de pares entre %d y %d: %d\n", numero1, numero2, sumaRango2);
               }
               break;

      case 7 : break;  

      } 
   }while(op != 7);
 
   return 0;
}