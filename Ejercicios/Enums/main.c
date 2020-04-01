#include <stdio.h>
#include "enums.h"

int main(){
   int opinion;

   do{
      opinion = llenarDiaSemanaMejorado();
      switch(opinion){
         case LUNES: printf("El dia es lunes \n");
         break;

         case MARTES: printf("El dia es martes \n");
         break;

         case MIERCOLES: printf("El dia es miercoles \n");
         break;

         case JUEVES: printf("El dia es jueves \n");
         break;

         case VIERNES: printf("El dia es viernes \n");
         break;
     }

      if(opinion == LUNES){
         printf("Es lunes \n");

      }else if(opinion == MARTES){
         printf("Es martes \n");

      }else if(opinion == MIERCOLES){
         printf("Es miercoles \n");

      }else if(opinion == JUEVES){
         printf("Es jueves \n");

      }else if(opinion == VIERNES){
         printf("Es viernes \n");
      } 
 
   }while(opinion >= 0 && opinion <= 4);

   return 0;
}
