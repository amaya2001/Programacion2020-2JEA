#include<bits/stdc++.h>
#define MAX 100

using namespace std;

map<string,int> mp;
set<string> camera;

void dfs( int v, bool visitado[], bool m[ MAX ][ MAX ], int ciudad, int s = -1 )
{
	visitado[ v ] = true;
	for( int i = 0; i < ciudad; ++i ){
		if( m[ v ][ i ] && !visitado[ i ] && i != s ){
		  dfs( i, visitado, m, ciudad, s );
    }
  }
}

int main()
{
	int ciudad, ruta, x = 0;
	string nombre[ MAX ], f, t;
  bool primero = true;

	while( cin >> ciudad ){ 
		bool m[ MAX ][ MAX ] = { { false } }; // Inicializacion
    bool p[ MAX ] = { false }; // Inicializacion

		if( primero ){
      primero = false;
    }
		else{
			cout << endl;
    }
		for( int i = 0; i < ciudad; ++i ){ 
      cin >> nombre[ i ];
			mp[ nombre[ i ] ] = i;
    }
		for( cin >> ruta; ruta = ruta - 1 && cin >> f >> t; ){ //https://stackoverflow.com/questions/16007441/cin-as-a-conditional-in-a-while-loop/16007456
			m[ mp[ f ] ][ mp[ t ] ] = m[ mp[ t ] ][ mp[ f ] ] = 1;
    }
		for( int i = 0; i < ciudad; ++i )
			if( !p[ i ] ){
				bool ct[ MAX ] = { false };
				int test = -1;

				dfs( i, ct, m, ciudad );
				for( int j = 0; j < ciudad; ++j ){
					if( j != i && ct[ j ] )
					{
						bool cmp[ MAX ] = { false };
	
						if( m[ i ][ j ] ){
						  test = j;
            }
						dfs( i, cmp, m, ciudad, j );
						cmp[ j ] = true;
						if( memcmp( ct, cmp, sizeof( ct ) ) ){
							camera.insert( nombre[ j ] );
            }
					}
      }
				if( test != -1 )
				{
					bool cmp[ MAX ] = { false };

					dfs( test, cmp, m, ciudad, i );
					cmp[ i ] = true;
					if( memcmp( ct, cmp, sizeof( ct ) ) ){
						camera.insert( nombre[ i ] );
          }
				}
				for( int j = 0; j < ciudad; ++j ){ 
				  p[ j ] |= ct[ j ]; // o binario
        }
			}

		cout << "City map #" << ++x << ": " << camera.size() << " camera(s) found" << endl;
		for( auto& s: camera ){ // https://stackoverflow.com/questions/8542873/c11-auto-semantics/8543161
		  cout << s << endl;
    }
	}
}