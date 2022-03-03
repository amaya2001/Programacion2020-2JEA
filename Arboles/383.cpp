#include<bits/stdc++.h>
using namespace std;

vector<vector< int > > adj( 100 );
vector< bool > vis( 100 );
vector< int > p( 100 ); 
int n, x = 1;
bool fnd;
map< string, int > names;

void bfsAux( int v, int h ){/// Me base en la implementacion del profe de bfs "listas" de adyacencia. 
  int u, w;
  queue< int > cola;
  vis[ v ] = true;
  cola.push( v );

  while( !cola.empty() ){
    
    w = cola.front();
    cola.pop();
    if( w == h ){ // w = final.
        fnd = true;
        return;
    }

    for( int i = 0; i < adj[ w ].size(); ++i ){
        v = adj[ w ][ i ];
        if( !vis[ v ] ){
            vis[ v ] = true;
            p[ v ] = w;
            cola.push( v );
        }
    }
  }
}

void bfs( int low, int high ){

    for( int i = 0; i < n; ++i ){
        vis[ i ] = false;
    }

    bfsAux( low, high );
}

int main(){
    int g, m, p1, cases, total;
    string name1, name2;
    cin>> cases;

    cout<< "SHIPPING ROUTES OUTPUT"<<endl <<endl;
     while( cases -- ){
        cout<< "DATA SET  "<<x++ <<endl <<endl;
        cin>> n>> m>> p1;

        for ( int i = 1; i <= n; ++i ){
            cin>> name1;
            names[ name1 ] = i; 
        }
        
        for ( int i = 0; i < m; ++i ){
            cin>> name1>> name2;
            adj[names[ name1 ] ].push_back( names[ name2 ] );
            adj[names[ name2 ] ].push_back( names[ name1 ] );
        }
        for ( int i = 0; i < p1; ++i ){
            
            cin>> g >> name1>> name2;
            for( int i = 0; i < n; ++i ){
                p[ i ] = -1;
                fnd = false;
                total = 0;
            }

            bfs( names[ name1 ], names[ name2 ] );

            if( fnd == true ){

                int node = names[ name2 ];
                while( node != names[ name1 ] ){
                    total++;
                    node = p[ node ];
                }
                cout<< "$" <<total * 100 * g<<endl;
            }else{
                cout<< "NO SHIPMENT POSSIBLE" <<endl;
            }

        }
        names.clear();
		for( int i = 0; i < n; ++i ){
			adj[ i ].clear();
        }
        cout<<endl;
    }
    cout<< "END OF OUTPUT" << endl;


  return 0;
}