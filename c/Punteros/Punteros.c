#include "Punteros.h"

void elevar2(int x, int *temp1){
	*temp1=pow(x,2);
	return;
}	
void sumar(int m, int n, int *temp2){
    *temp2 = m+n;
	return;
}	
void intercambio(int *c, int *d){
    int temp;
    temp = *c; *c = *d; *d = temp;
    return;
}
	

