#include <iostream>
using namespace std;

int main() {

int Y, P;
int popes[ 100000 ];

while( scanf( "%d", &Y ) != EOF ){
	    scanf( "%d", &P );

	for( int i = 0; i < P; ++i ){
		scanf( "%d", popes + i ); // De esta manera no toma el primer numero.
		//printf("seq: ", seq);
    }

	int max1 = 0;
	int from, to;
	//printf("%d %d\n",Y,P);
	for( int i = 0; i < P; ++i ){
		int low = i;
		int high = P;
		int target = popes[ i ] + Y - 1; // Este es mi N + Y - 1 
		while( low < high ) {
			int mid = ( low + high ) / 2;
			if( target >= popes[ mid ] ){
                low = mid + 1;
            }	
			else{
                high = mid; // no se le resta 1
            }	
		}
		//printf("%d %d\n",ed, i);
		int max2 = high - i;
		if( max1 < max2 ){
			from = popes[ i ];
			max1 = max2;
			to = popes[ high - 1 ];
		}
	}
	//cout<<maxi<<from<<to<<endl;
	printf( "%d %d %d\n", max1, from, to );
}
    return 0;

}
