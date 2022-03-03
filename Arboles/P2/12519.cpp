#include <iostream>
#define INF (1<<29)
#define MAX 105
using namespace std;


int n, m, f[ MAX ][ MAX ];


int main(){
    int u, v, w;
	while( cin>>n >>m, n || m )
	{
	      for( int i = 1; i <=  n ; ++i ){
              for( int j = 1; j <=  n ; ++j ){
                  f[i][j] = INF;
              }
          } 
	      for(int i = 1; i <=  n ; ++i ){
              f[i][i] = 0;
          } 

		while(m > 0)
		{
			cin>>u >>v >>w;
			f[ u ][ v ] = w;
			f[ v ][ u ] = -w;

            m = m - 1;
		}

		 for( int k = 1; k <=  n ; ++k ){
              for( int i = 1; i <=  n ; ++i ){
                   for( int j = 1; j <=  n ; ++j ){
		                f[ i ][ j ] = min( f[ i ][ j ], f[ i ][ k ] + f[ k ][ j ] );
                   }
              }
         }
		if( f[ 1 ][ 1 ] < 0 ){
            cout<<"Y"<<endl;
        }
		else{
            cout<<"N"<<endl;
        } 
	}
	return 0;
}

