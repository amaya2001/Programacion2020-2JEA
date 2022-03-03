#include <iostream>
using namespace std;

int Arreglo[] = { 1,1,2,1,2,3,1,2,3,4,1,2,3,4,5,1,2,3,4,5,6,1,2,3,4,5,6,7,1,2,3,4,5,6,7,8,1,2,3,
                4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,11,1,2,3,4,5,6,7,8,9,10 };

void EncontrarDato( int dato ) {
	int inicio = 0, medio = 0, final = sizeof( Arreglo );

		while( inicio <= final ){
			medio = ( inicio + final ) / 2;
			if( Arreglo[ medio ] > dato ) {
				final = medio - 1;
 			}else{
				if( Arreglo[ medio + 1 ] <= dato ){
					inicio = medio + 1;
				}else{
					break;
				}
			}
		}
	cout<< Arreglo[ dato - Arreglo[ medio ] - 1 	];
    cout<< endl;
}

    int main(){
        int casos, datos;

        cin>> casos;
        while( casos > 0 ){
            cin>>datos;
            EncontrarDato( datos );
			casos = casos - 1;
        }
    return 0;
}
