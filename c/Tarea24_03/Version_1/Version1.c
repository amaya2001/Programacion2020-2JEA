#include "Version1.h"

const char* getMes(int mes){
 
   switch (mes){
      case 1: return "Enero";
      case 2: return "Febrero";
      case 3: return "Marzo";
      case 4: return "Abril";
      case 5: return "Mayo";
      case 6: return "Junio";
      case 7: return "Julio";
      case 8: return "Agosto";
      case 9: return "Septiembre";
      case 10: return "Octubre";
      case 11: return "Noviembre";
      case 12: return "Diciembre";
   }
}

int menu(){
   int opc;

   printf("\n1) Ingresar Persona\n");
   printf("2) Buscar cumpleanios por el mes\n");
   printf("3) Recursion\n");
   printf("4) Ejemplo con enums,condicional,etc\n");
   printf("5) Imprimir\n");
   printf("0) Salir\n");
   printf("Opcion: ");
   scanf("%d", &opc);

   return opc;
}

int contarMes(int num){
   int cont = 0;
   while(num > 0){
      if(num % 2 == 0){
         cont ++;
      }
   num--; 
   contarMes(num);
   }

   return cont;
}