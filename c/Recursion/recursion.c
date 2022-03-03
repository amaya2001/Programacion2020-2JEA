#include <stdio.h>
#include "recursion.h"

int menu(){

   int opc;
   printf("\n==================================\n");
   printf("             RECURCION\n");
   printf("==================================\n");
   printf("1) Imprimir los numeros del 1 al 5\n");
   printf("2) Multiplicacion de dos numeros enteros\n");
   printf("3) Conteo de los numeros pares del 0 al 10\n");
   printf("4) Suma de los numeros pares del 0 al 10\n");
   printf("5) Conteo de los numeros pares entre rengos\n");
   printf("6) Suma de los numeros pares entre rangos\n");
   printf("7) Salir\n");
   printf("Opcion: ");
   scanf("%d", &opc);
   
   return opc;
}

int lista5(int num1){
   if(num1 > 0){
      printf("%d ", num1);
      num1--;
      lista5(num1);    
   }   
}

int multi(int num1, int num2){
   if(num1 > 0 && num2 > 0){
      return num1 +multi(num1,num2-1);   
   }
}

int contarPares(int numAct){
   int cont = 0;
   while(numAct > 0){
      if(numAct %2 == 0){
         cont ++;
      }
   numAct--;
   contarPares(numAct);
   }

   return cont;
}

int sumarPares(int numAct){
   if(numAct==0){
      return 0;
   }
   else if(numAct %2 == 0){
      return  numAct + sumarPares(numAct - 1);
   }
   else{
      return sumarPares(numAct - 1);
   }
}

int rangoConteo(int num1, int num2){
   int cont = 0;
   if(num1 >= num2){
      while(num1 > num2){
         if(num1 %2 == 0){
            cont ++;
         } 
      num1--;
      rangoConteo(num1, num2);
      }

   return cont;
   }
   else if(num2 >= num1){
      while(num2 > num1){
         if(num2 %2 == 0){
            cont ++;
         } 
      num2--;
      rangoConteo(num1, num2);
      }

   return cont;

   }   
}

int sumarParesRango(int numAct1, int numAct2){
   if(numAct1 == 0 && numAct2 == 0){
      return 0;
   }
   if(numAct1 > numAct2){
      if(numAct1 %2 == 0){
         return  numAct1 + sumarParesRango(numAct1 - 1,numAct2);
      }
   else{
      return sumarParesRango(numAct1 - 1,numAct2);
   }
   }
   else if(numAct2 > numAct1){
       if(numAct2 %2 == 0){
          return  numAct2 + sumarParesRango(numAct1 ,numAct2-1);
       }
       else{
          return sumarParesRango(numAct1,numAct2-1);
       }
   }
}  

