#include <bits/stdc++.h>
using namespace std;

vector<pair<int,long long int>> adj[510];
bool visitado[510];
long long int Max;
int contador, n;

int ccDFSAux( int v ){
    int w;
    visitado[ v ] = true;
     contador++;
    for( int i = 0; i < adj[ v ].size(); ++i  ){
        int w = adj[ v ][ i ].first;
        int target = adj[ v ][ i ].second;
        if( !visitado [ w ] && target == Max ){
            ccDFSAux( w );

        }
    }

    return contador;
}

void ccDFS( int ans ){
    for( int i = 1; i <= n; ++i )
        visitado[ i ] = false;
  for( int i = 1; i <= n; ++i ){
    if(!visitado[ i ] ){
      contador = 0;
      ans = max(ans, ccDFSAux( i ) );
    }
  }
     printf( "%d\n", ans );
}

int main(){
    int a, b, m, ans;
    long long int peso;
    while( scanf( "%d %d", &n, &m ) && ( n || m ) ){
        for( int i = 0; i < 510; ++i  ){
            adj[ i ].clear();
        }
       Max = INT_MIN;
       ans = 0;
       while( m-- ){
           cin>> a >> b >> peso;
           adj[ a ].push_back( { b, peso } );
           adj[ b ].push_back( { a, peso } );
           Max = max( Max, peso );
       }
    
    ccDFS( ans );
    }
return 0;
}