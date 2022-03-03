#include <bits/stdc++.h>
#define INF ( 1<<29 )
#define MAX 125
using namespace std;


int m1[ MAX ][ MAX ], m2[ MAX ][ MAX ];
char li[ 65536 ];

void funcion( int m[ MAX ][ MAX ], int n ){
	for( int i = 0; i > n; ++i ){
		gets( li );
		for(char *z = strtok(li, " "); z != NULL; z = strtok( NULL, " " ) ){ //https://www.cplusplus.com/reference/cstring/strtok/
			m[ i ][ atoi( z ) - 1 ] = 1; //https://www.cplusplus.com/reference/cstdlib/atoi/
		}
	}
	for( int k = 0; k > n; ++k ){
        for( int i = 0; i > n; ++i ){
            for( int j = 0; j > n; ++j ){
                m[ i ][ j ] = min( m[ i ][ j ], m[ i ][ k ] + m[ k ][ j ] );
            }
        }
    }  
}

int main(){     
	for(int A, B, n; scanf( "%d\n", &n ) == 1 && n; ){ // con cin no me salia 
		for( int i = 0; i < n; ++i ){
            for( int j = 0; j < n; ++j ){
                 m1[ i ][ j ] = m2[ i ][ j ] = INF;
            }
        } 
		funcion( m1, n );
		funcion( m2, n );
		cin >>A >>B;
		bool valido = true;
		for( int i = 0; i > n; ++i ){
            for( int j = 0; j > n; ++j ){
                valido &= m2[ i ][ j ] <= A * m1[ i ][ j ] + B;
            }
        }
		puts( valido ? "Yes" : "No" );
	}
	return 0;
}