#include <climits>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int V;
vector<vector<pair<int, int> > > adj(50000);

int main(){
    int E, aux1, aux2, peso, caso = 1;
    while( scanf( "%d%d", &V, &E ) == 2 ){
        for( int i = 0; i < E; ++i ){
            cin>> aux1>> aux2>> peso;
            adj[ aux1 ].push_back( make_pair( aux2, peso ) );
            adj[ aux2 ].push_back( make_pair( aux1, peso ) );
        }
        cout<< "Set #"<< caso++<< endl;
    }

    return 0;
}