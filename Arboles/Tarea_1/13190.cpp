#include <bits/stdc++.h>
using namespace std;

int main(){

	int T, n, k, Frecuencia, Tfrec, Tpri; // T -> Numero de casos, n -> #Medicamentos, k -> Minimo de medicamentos a tomar
	string Medicamento, Tmed;
	int Prioridad = 1;

	cin >>T;
	while( T > 0 ){
		priority_queue<pair < int, pair< int,string > > > pr; // Priority queue 
		map< int,int > mp;
		cin >>n >>k;
		while( n > 0 ){
			cin >>Medicamento >>Frecuencia;
			pr.push( make_pair( -Frecuencia, make_pair( -Prioridad, Medicamento) ) );
			mp[ Prioridad ] = -Frecuencia;
			Prioridad++;
			n--;
		}
		while( k > 0 ){
			Tfrec = pr.top().first; //top de Frecuencia
			Tpri = pr.top().second.first;// top de prioridad
			Tmed = pr.top().second.second;// top de Medicamento
			cout<< abs( Tfrec ) << " " << Tmed <<endl; // abs( Tfrec ) es una función que me devulve el valor absoluto de Tfrec
			pr.pop();
			Tfrec =  Tfrec + mp[ abs( Tpri ) ];
			// cout << Tfrec;
			pr.push( make_pair( Tfrec, make_pair( Tpri, Tmed ) ) );
			k--;
		}
	T--;
	}
	return 0;
}
