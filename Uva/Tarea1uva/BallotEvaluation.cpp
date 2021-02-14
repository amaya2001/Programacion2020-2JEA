#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string,int> Mapa;

int EsOperacion( char Condicion1, char Condicion2 = ' ' ){
    if ( Condicion2 == ' ' ){
        if( Condicion1 == '<' ){
            return 1;
        }
        if( Condicion1 == '>' ){
            return 2;
        }
        if( Condicion1 == '=' ){
            return 3;
        }
    }
    else{
        if ( Condicion1 == '<' && Condicion2 == '=' ) {
            return 4;
        }
        else if ( Condicion1 == '>' && Condicion2 == '=' ) {
            return 5;
        }
    }
}

int main() {
    char Condicion1, Condicion2;
    int Num1, Num2, Constante1, Constante2, Num, Opcion;
    string Posicion;
    bool EsCorrecto = true;

    cin >> Constante1 >> /*Condicion2*/ Constante2;
    for( int i = 1; i <= Constante1; ++i ) {
        cin >> Posicion >> Num1 >> Condicion1 >> Num2;
        Mapa[ Posicion ] = Num1 * 10 + Num2 /* *10 */;
    }
    for ( int Resultado = 0; Resultado < /*Condicion2*/ Constante2; ++Resultado ){
    int suma = 0;
        while ( cin >> Posicion ) {
            suma = suma + Mapa[ Posicion ];
            cin >> Condicion1;
            if ( Condicion1 == '+' ) {
                continue;
            }
            break;
        }
        if( cin.peek() != ' ' ){
            cin >> Condicion2;
            Opcion = EsOperacion( Condicion1, Condicion2 );
        }
        else {
            Opcion = EsOperacion( Condicion1 );
        }

        cin >> Num;

        Num = Num * 10;
        if( Opcion == 1 ){
            EsCorrecto = suma < Num;
         }
        else if( Opcion == 2 ){
            EsCorrecto = suma > Num;
        }
        else if( Opcion == 3 ){
            EsCorrecto = suma == Num;
        }
        else if( Opcion == 4 ){
            EsCorrecto = suma <= Num;
        }
        else if( Opcion == 5 ){
            EsCorrecto = suma >= Num;
        }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if ( EsCorrecto ){
        cout << "Guess #" << Resultado + 1 << " was correct.";
        cout << endl;
        }
        else{
        cout << "Guess #" << Resultado + 1 << " was incorrect.";
        cout << endl;
        }
    }

    return 0;
}
