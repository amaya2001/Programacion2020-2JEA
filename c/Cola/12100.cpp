#include<cstring>
#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
const int Maxn = 100+10;

int uni[Maxn];
int n, m;
int num[ 10 ];
int ma = 0;

struct node
{
    int id, rank;
}   p[ 110 ];
queue<node> q;

int main(){
    int ncase;

    cin>> ncase;
    while( ncase-- ){
        while( !q.empty() )
        {
            q.pop();
        }
        
        memset( num, 0, sizeof( num ) );

        cin>>n>>m;
        int tmp;
        node now, next;
        for( int i = 0; i < n; ++i ){
            cin>>tmp;
            ma = max( ma, tmp );
            p[ i ].id = i;
            p[ i ].rank = tmp;
            q.push( p[ i ] );
            num[ tmp ]++;
        }
        bool flag = false;
        int ans = 0;
        while( !flag ){
            while( 1 ){
                now = q.front() ;
                q.pop();
                if( now.rank == ma ){
                    ans++;
                    if( now.id == m ){
                        flag = true;
                    }
                    num[ ma ]--;
                    while( num[ ma ] == 0 )
                    {
                        ma--;
                    }
                    break;
                }
                else
                    q.push( now );
    
        }
        cout<< ans  <<endl;

    }
    return 0;
}