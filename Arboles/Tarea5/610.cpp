#include <bits/stdc++.h>
using namespace std;

#define MAX  1010
vector<vector<int> > adj(50000);
set<pair<int, int> > bridges;
int visitado[ MAX ];
int low[ MAX ];
int padre[ MAX ];
int n, t;
void bridgesAux(int);

void bridgesAux( int v ){
  int w;
  visitado[ v ] = low[ v ] = ++t;

  for( int i = 0; i < adj[ v ].size(); i++ ){
    w = adj[ v ][ i ];
    if(visitado[ w ] == -1){
      padre[ w ] = v;
      bridgesAux(w);
      bridges.insert( make_pair( v, w ) );

      low[ v ] = min( low[ v ], low[ w ] );

      //verificar si es un puente
    if(low[ w ] > visitado[ v ])
	    bridges.insert( make_pair( w, v ) );
    }
    else if(w != padre[v])
        bridges.insert( make_pair( v, w ) );
        low[ v ] = min( low[ v ], visitado[ w ] );
      
  }
}

void bridgesTarjan(){

  for( int i = 1; i <= n; i++ )
    low[ i ] = visitado[ i ] = padre[ i ] = -1;

  for( int i = 1; i <= n; i++ )
    if( visitado[ i ] == -1 )
      bridgesAux( i );
}

int main(){
    int m, a, b, tt = 0;
    while( scanf( "%d %d", &n, &m ) && ( n || m ) ){
        
        cout << ++tt << endl << endl;

        for( int i = 1; i <= m; ++i ){
            cin>> a >> b;
            adj[ a ].push_back( b );
            adj[ b ].push_back( a );

        }
        t = 0;
        bridgesTarjan();
  
      for(set<pair<int, int> >::iterator it = bridges.begin(); it !=  bridges.end(); ++it){
        cout << it->first << " " << it->second << endl;
      }
            
      cout << "#\n";

        memset( visitado, 0, sizeof( visitado ) );
        memset( low, 0, sizeof( low ) );
        for( int i = 1; i <= n; i++ )
            adj[ i ].clear();
        
    }
    return 0;

}