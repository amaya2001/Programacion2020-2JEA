#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// int tam = strOriginal.size();
priority_queue<pair<int, int> > Queue;

void impresion( int Consultas, int PrimerHeap, int SegundoHeap, map<int, int> Mapa ){
 for( int i = 1; i <= Consultas; ++i ) {
    PrimerHeap = Queue.top().first;
    SegundoHeap = Queue.top().second;
    PrimerHeap = PrimerHeap - Mapa[ -SegundoHeap ];
    cout << -SegundoHeap;
    cout << endl;
    Queue.pop();
    Queue.push( make_pair( PrimerHeap, SegundoHeap ) );
  }

}
int main() {
map<int, int> Mapa;
string strOriginal;
int Registro1, Registro2, Consultas, SegundoHeap, PrimerHeap;

    while ( true ) {
        cin >> strOriginal;
        if ( strOriginal == "#" ){
            break;
        }
    cin >> Registro1;
    //cout << Registro1;
    cin >> Registro2;
    //cout << Registro2;
    Mapa[ Registro1 ] = Registro2; 
    Queue.push( make_pair( -Registro2, -Registro1 ) );
    }
    cin >> Consultas;
    impresion( Consultas, SegundoHeap, PrimerHeap, Mapa );
  return 0;
}