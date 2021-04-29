#include<iostream>
#include <vector>

using namespace std;
#define MAX 1000

vector<int> vec[ MAX ] = {};
int visitado[ MAX ] = {};

void dfs( int n ) {
    visitado[ n ] = 1;
    for( int i = 0; i < vec[ n ].size(); ++i ){
        if( visitado[ vec[ n ][ i ] ] == 0 ){
            dfs( vec[ n ][ i ] );
        }
    }
}

int main() {
    int casos, tam, it1, it2, num, num1, num2, resultado = 0;

    cin>>casos;
    while( casos > 0 ) {
        cin>>tam;
        for( int i = 0; i <= tam; ++i ){
            visitado[ i ] = 0;
        }
        cin>>it1 >>it2;
        while( it1 > 0 ) {
            cin>>num1 >>num2;
            vec[ num1 ].push_back( num2 );
            it1 = it1 - 1;
        }
        while( it2 > 0 ) {
            cin>>num;
            dfs( num );
            it2 = it2 - 1;
        }
//////////////////////////////////////////////////
        for( int i = 0; i <= tam; ++i ){
            resultado = resultado + visitado[ i ];
        }
        cout<<resultado;
        cout<<endl;
    casos = casos - 1;
    }
    return 0;
}
