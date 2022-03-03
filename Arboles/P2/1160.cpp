#include <vector>
#include <iostream>
#define MAX 100001
using namespace std;

int padre[ MAX ], rango[ MAX ];

void makeSet( int v ){
  padre[ v ] = v;
  rango[ v ] = 0;
}

int findSet( int v ){
    if( v == padre[ v ] )
        return v;  
    else{
        padre[ v ] = findSet( padre[ v ] );
        return padre[ v ];
    }
}
void unionSet( int a, int b ){
    
    int u = findSet( a );
    int v = findSet( b );
    if(u != v){
        if( rango[ u ] < rango[ v ] )
            swap( u, v);
    
    padre[ v ] = u;
    if( rango[ u ] == rango[ v ] )
        rango[ u ]++;
  }
}

int main(){

    int a, b, n = MAX, total = 0;


     while ( scanf( "%d", &a ) == 1 ){
        if( a == -1 ){
            cout<<total<<endl;

            for( int i = 0; i < n; i++ )
                makeSet( i );
        }
        else
        {
            cin>>b;
            unionSet( a, b );
            total++;
        
        }
    }
    return 0;
}