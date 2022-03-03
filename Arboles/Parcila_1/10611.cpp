#include <iostream>
#define MAX 50000
using namespace std;

int mon[ MAX ];
int n, q;
int b;
int lower;

int main(){
    cin >>n; 

    for( int i = 0; i < n; ++i ){
        cin>>mon[ i ]; 
    }

    cin>>q;

    for( int i = 0; i < q; ++i ){
        cin>>b; 
    
    int low = 0;
    int high = n - 1; 

    while( low <= high ){
        int mid = ( low + high ) / 2; 
        if( b > mon[ mid ]){ 
            low = mid + 1; 
        }
        else{
            high = mid - 1; 
        }
        if( mon[ mid ] == b ){ 
            lower = mid; 
        }
        if( low > high ){
            lower = mid;
        }
    }
        int upper = lower; 

        while( mon[ lower ] >= b ){
            lower--;
        }
        while( mon[ upper ] <= b ){
            upper++;
        }
        if( lower == -1 ){
            cout<<"X ";
        }
        else{
            printf( "%d ", mon[ lower ] ); 
        }
        if(upper >= n){
            cout<<"X\n";
        }
        else{
            cout<<mon[ upper ]<<endl;
        }

    }
    return 0;
}