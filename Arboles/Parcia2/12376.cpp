#include<bits/stdc++.h>
using namespace std;

vector< vector< int > > adj( 100 );
vector< int > vis( 100 );
int value[ 100 ], MaxUnit, high, n = 0;

void dfsAux( int w, int sum ){ /// Me base en la implementacion del profe de dfs "listas" de adyacencia. 
    int u, next, add = -1;
    vis[ w ] = 1;
    for( int i = 0; i < adj[ w ].size(); ++i ){
        u = adj[ w ][ i ];
        if( value[ u ] > add ){
            add = value[ u ];
            next = u;
        }
    }
    if( add == -1 ) {
		MaxUnit = sum;
		high = w;
	    return;
	}
	dfsAux( next, sum + add );

}

void dfs( int node, int s ){

    for(int i = 0; i < n; ++i ){
        vis[ i ] = 0;
    }
    dfsAux( node, s );
}

int main(){
    int t, m, n, u, v, cases = 1;
    cin>> t;
    while( t-- ){
        cin>>n >>m;
        for( int i = 0; i < n; ++i ){
            cin>> value[ i ];
        }
            for( int j = 0; j < m; ++j ){
                cin>> u >> v;
                adj[ u ].push_back( v );

        }
        dfs( 0, 0 );
        cout << "Case " << cases++ << ": "<< MaxUnit << " " << high << endl;
        for( int i = 0; i < n; ++i ){
            adj[ i ].clear();
        }
    }
    return 0;
}


