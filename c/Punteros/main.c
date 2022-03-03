  
#include "Punteros.h"
int main() {
	int a=3;
	int b=2;
	int temp1;
	int temp2; 
	elevar2(a, &temp1);
	sumar(a, b, &temp2);
	intercambio(&a, &b);
	printf("Numero elevado: %d\n",temp1 );
	printf("Sumar dos numeros: %d\n", temp2);
	printf("intercambio: %d %d\n",a,b);
	return 0;
}