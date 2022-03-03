#include <iostream>
#include <cstring> // Para el memset
#include <vector>
using namespace std;

vector< int > vec[ 1000 ]; 
int num[ 1000 ], minimo[ 1000 ], vistos[ 1000 ];
int t, numero;

void dfs( int u , int parejas ){
    num[ u ] = minimo[ u ] = numero++;
    vistos[ u ] = 1; // Empieza desde 1
    for( int i = 0 ; i < vec[ u ].size() ; ++i ){
        int y = vec[ u ][ i ];

        if( !vistos[ y ] )
        {
            cout<<u<<y<<endl;
            dfs( y , u );
            if( num[ u ] < minimo[ y ] ){
                cout<<y<<u<<endl;
            }
            minimo[ u ] = min( minimo[ u ] , minimo[ y ] ); // Me devuelve el minimo entre minimo[u] y minimo [y], en caso de que sean iguales me devuelve minimo[u]
        }
        else if( num[ u ] > num[ y ] && y != parejas  ){
            cout<<u<<y<<endl;
            if( minimo[ u ] > num[ y ] ){
                minimo[ u ] = num[ y ];
            }
        }
    }
}

int main(){
    int datos , w , x , c = 1; // Empiza desde 1

    while( cin>>t >>datos &&  ( t | datos ) ){
        while( datos > 0 ){
            cin>>w >>x;
            vec[ w ].push_back( x );
            vec[ x ].push_back( w );
            datos = datos - 1;
        }
        memset( vistos , 0 , sizeof( vistos ) );
        numero = 1;
        cout<<c++<<endl<<endl;
        dfs( 1 , -1 );
        cout<<"#"<<endl;
        for( int i = 1; i <= t; ++i ){ 
            vec[ i ].clear(); // Hay que limpiar el vector.
        }
    }
    return 0;
}