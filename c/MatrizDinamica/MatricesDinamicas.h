#include <stdio.h>
#include <stdlib.h>

typedef struct Estudiante{
   char nombre[40];
   int notaF;
}Estudiante;

//Reserva el espacio para las filas y las columnas de la matriz
Estudiante ** reservarMatriz(int fil, int col); 

// LLena
void llenarMatriz(Estudiante ** pMatriz , int fil, int col); 

// Muestra la matriz 
void mostrarMatriz(Estudiante ** pMatriz , int fil, int col); 

//Completar con las que faltan