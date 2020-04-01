#include <stdio.h>
#include "enums.h"

dias_semana_e llenarDiaSemanaMejorado(){
   dias_semana_e diaUsuario;

   printf("Ingrese numero de la semana: ");
   scanf("%d", &diaUsuario);

   return diaUsuario;
}

