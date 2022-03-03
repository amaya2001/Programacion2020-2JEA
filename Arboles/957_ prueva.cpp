#include <iostream>
using namespace std;

int main() {

int Y, P;
int seq[ 100000 ];

while( scanf( "%d", &Y ) != EOF ){
	    scanf( "%d", &P );

	for( int i = 0; i < P; ++i ){
		scanf( "%d", seq + i );
    }

	int maxi = 0;
	int from, to;
	//printf("%d %d\n",Y,P);
	for( int i = 0; i < P; ++i ){
		int low = i;
		int high = P;
		int target = seq[ i ] + Y - 1; // Este es mi N + Y - 1 
		while( low < high ) {
			int mid = ( low + high ) / 2;
			if( target >= seq[ mid ] ){
                low = mid + 1;
            }	
			else{
                high = mid;
            }	
		}
		//printf("%d %d\n",ed, i);
		int num = high - i;
		if( maxi < num ){
			maxi = num - 1;
			from = seq[ i ];
			to = seq[ high ];
		}
	}
	printf( "%d %d %d\n", maxi, from, to );
}
    return 0;

}
