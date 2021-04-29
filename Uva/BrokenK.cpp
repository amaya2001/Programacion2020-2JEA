#include<iostream>
#include<list>

using namespace std;

int main(){
    string listaOriginal;
    while( cin>>listaOriginal ){
        list<char>::iterator iterador;
        list<char>listaFinal;
        int tam = listaOriginal.size();
        iterador = listaFinal.begin();

        for( int i = 0; i < tam; ++i ){
            if( listaOriginal[ i ] == '[' ){
                iterador = listaFinal.begin();
            }
            else if( listaOriginal[ i ] == ']' ){
                iterador = listaFinal.end();
            }
            else{
                listaFinal.insert( iterador, listaOriginal[ i ] );
            }
        }
        for( iterador = listaFinal.begin(); iterador != listaFinal.end(); ++iterador ){ // https://www.geeksforgeeks.org/vectorbegin-vectorend-c-stl/
            cout<<*iterador;
        }    
        cout<<endl;
    }
    return 0;
}
