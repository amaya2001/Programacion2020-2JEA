#include <stdio.h>

typedef struct persona{
   char nombre[ 30 ];
   int diaNacimiento, mesNacimiento, anoNacimiento; 

}persona_t;


 typedef enum mesesdelano{
	ENERO = 1,
	FEBRERO = 2,
	MARZO = 3,
	ABRIL = 4,
	MAYO = 5,
        JUNIO = 6,
	JULIO = 7,
	AGOSTO = 8,
	SEPTIEMBRE = 9,
	OCTUBRE = 10,
	NOVIEMBRE = 11,
	DICIEMBRE = 12

} meses;

struct persona llenarPersona(){
	persona_t persona;
        fflush(stdin);

	printf("Ingrese un nombre: ");
	scanf("%s", &persona.nombre); 
	printf("Ingrese el dia de nacimiento: ");
	scanf("%d", &persona.diaNacimiento); 
	printf("ingrese el mes de nacimiento: ");
	scanf("%d", &persona.mesNacimiento);
	printf("ingrese el anio de nacimiento: ");
	scanf("%d", &persona.anoNacimiento); 

	return persona;
}

// ================= AQUI ===================
// calendario[mes][posicion libre]
// 0 9 0 1 0 0 0 0 3  0  0  0   =  contador[12]
// 0 1 2 3 4 5 6 7 8  9 10 11

void llenarMatriz(persona_t matrizAno[ 12 ][ 5 ], int contador[ 12 ]){
        persona_t personaCopy;
	int mes;

        personaCopy = llenarPersona();  
        mes = personaCopy.mesNacimiento - 1;  
	if(contador[mes]>=5){
  		printf("Esta lleno\n");
		return;
	}
  
	matrizAno[mes][contador[mes]] = personaCopy;
        contador[mes]+=1;
  	return;
}

void mostrarMatriz(persona_t matrizAno[12][5], int contador[12]){   
	int i, j;

	for(i = 0; i < 12; i++){ //<---- Este recorre los meses
		for(j = 0; j < contador[i]; j++){// <---- Este recorre las personas del mes
			printf("%s ", matrizAno[i][j].nombre);
                        printf("%d ",matrizAno[i][j].diaNacimiento);
                        printf("%d ", matrizAno[i][j].mesNacimiento);
                        printf("%d\n ", matrizAno[i][j].anoNacimiento);
	}
  		}

}

int mostrarMenu() {
	int opcion = 0,resultado;

	printf("\nOpciones que puedes realizar\n");
	printf("1) Agregar un usuario\n");
	printf("2) Buscar por mes de nacimiento\n");
        printf("3) Mostrar matriz\n");
	printf("0) Salir\n");
	printf("Opcion: ");
	scanf("%d", &opcion);

  return opcion;
}


int main(){
	int opcion;
	persona_t matrizano[12][5]={};
	int contador[12] = {};
   
	do{
  		opcion = mostrarMenu();
  		switch (opcion) {
			case 1: llenarMatriz(matrizano, contador);
				break;

                	case 3: mostrarMatriz(matrizano, contador);
				break;			
		
		}
	}while(opcion != 0);
	
	return 0;
}