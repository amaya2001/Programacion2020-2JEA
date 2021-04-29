#include <iostream>
#include <math.h>
using namespace std;
#define PI acos( -1 )
#define MAX 50

int main() {
    double  n, C, L;

    while( true ){ // Perdon profe =(
        cin>>L >>C >>n;
        double LPrima = ( 1 + n * C ) * L, high = 0, low = PI / 2, mid = 0, resultado = 0;
        int contador = 0, formula = 0;

        if( n >= 0 ){
            while( contador < MAX && high <= low ) {
                mid = ( high + low ) / 2.0;
                resultado = L / 2 / sin( mid );
                formula = resultado * 2 * mid;
                if( formula < LPrima ){
                    high = mid;
                }
                else{
                    low = mid;
                }
            contador = contador + 1;
            }
        printf( "%.3lf", resultado - resultado * cos( mid ) ); //No pude encontrar un cout que imprimiera como un .3fl
        cout<<endl;
        }else{
            
            break;
        }
    }
    return 0;
}
