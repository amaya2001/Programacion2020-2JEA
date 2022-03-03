#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, line, x;

    while( scanf( "%d", &n ) != EOF ){
        stack< int > s; queue< int > q; priority_queue< int > pq;
        bool Stack = true, Queue = true, Priority_Queue = true;
        while( n -- ){
            cin>> line >> x;
            if( line == 1 ){
                s.push( x ); q.push( x ); pq.push( x );
            }
            else{
                    if( s.empty() || s.top() != x ){ 
                        Stack = false;
                    }
                    else{
                        s.pop();
                    }
                
                    if( q.empty() || q.front() != x ){ // Devuelve una referencia al primer elemento de la cola.
                        Queue = false;
                    }
                    else{ 
                        q.pop();
                    }
                
                    if ( pq.empty() || pq.top() != x ){ 
                        Priority_Queue = false;
                    }
                    else{ 
                        pq.pop();
                    }
            }
        }
        
        if( Stack && !Queue && !Priority_Queue){
            cout << "stack"<<endl;
        }
        else if( Queue && !Stack && !Priority_Queue ){
            cout << "queue"<<endl;
        }
        else if( Priority_Queue && !Stack && !Queue ){
            cout << "priority queue"<<endl;
        }
        else if( !Stack && !Queue && !Priority_Queue ){
            cout << "impossible"<<endl;
        }
        else{ 
            cout << "not sure"<<endl;
        }
    }

    return 0;
}