#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

vector<int> vec[ 100002 ];
vector<int> orden;
int visitado[ 100002 ];

void dfs1( int u ){
    visitado[ u ] = true;
    for( unsigned int i = 0; i < vec [u].size(); i++ )
    {
        if( !visitado[ vec[ u ][ i ] ] ){
            dfs1( vec[ u ][ i ] );
        }
    }
    orden.push_back( u );
}

void dfs2( int u )
{
    visitado[ u ] = true;

    for( unsigned int i = 0; i < vec[ u ].size();i++ ){
        if( !visitado[ vec[ u ][ i ] ] ){ 
            dfs2( vec[ u ][ i ] );
        }
    }
}
int main (){
int num, m, T, cs = 1;

cin>>T;
    while ( T > 0 ){
      cin >>num >>m;
      int adj,u,v,i;

       memset(visitado,0,sizeof visitado);
       memset(vec,0,sizeof vec);
       orden.clear();

      while( m > 0 ){
          cin>>u>>v;
          vec[ u ].push_back( v );
          m = m - 1;
      }
      for( i = 1; i <= num; ++i ){
        if( !visitado[ i ] ){
            dfs1( i );
        }
      }
      memset( visitado, false, sizeof visitado );
      int cnt = 0;
      for ( i = 0 ; i < num ; ++i )
      {
        u = orden[ num - 1 - i ] ;
        if ( ! visitado[ u ] ) {
            dfs2( u );
            cnt++;
        }
      }
     cout<<cnt<<endl;
     T--;
    }
    return 0;
}