#include <stdio.h>
#define CAP 10

typedef struct Persona{
  char nombre[ 20 ];
  int dia, mes, anio;

} Persona;

typedef enum meses_e{
   ENE, FEB, MAR, ABR, MAY, JUN, JUL, AGO, SEP, OCT, NOV, DIC

}meses_e;

const char* getMes(int mes);

int menu();

int contarMes(int num);