#include <bits/stdc++.h>
using namespace std;

int main()
{
	int nCasos, NumCand, Voto;
	string Nombre, Partido, Ganador;

    scanf("%d\n",&nCasos);
	while( nCasos -- ){
		map<string, int> mp1;
		map<string, string> mp2;
		int T = 0;
		bool flag = false;

        scanf("%d\n",&NumCand);
		while(  NumCand -- ){
			getline( cin, Nombre );
			getline( cin, Partido );
			mp2[  Nombre ] = Partido ;
		}
        scanf("%d\n",&Voto);
		while(  Voto -- ){
			getline( cin, Nombre );
			if( mp2.find( Nombre ) != mp2.end() ){ //
				++mp1[ Nombre  ];
			}
		}
		map<string, int> :: iterator it;
		for(  it = mp1.begin(); it!= mp1.end(); ++it ){
			if( it->second > T ){
				T = it->second;
				flag = false;
				Ganador = it->first;
			}
			else if( it->second == T ){
				flag = true;
			}
		}
		if( !T || flag ){
			printf( "tie\n" );
		}
		else{
			cout<< mp2[ Ganador ] <<endl;
		}
		if( nCasos ){
			printf( "\n" );
		}
	}
}