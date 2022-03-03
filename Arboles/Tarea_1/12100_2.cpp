#include <bits/stdc++.h>
using namespace std;

int main(){
	int Casos, Tcola, Tpos, Top, OrdenTemp, PosTemp;	

	cin >>Casos;
	while( Casos-- ){
	deque<pair<int,int>> dq;
	priority_queue<int> pq;
		cin>>Tcola >>Tpos;
		int Orden, Pos = 0;
		for( int i = 0; i < Tcola; ++i ){
			cin >>Orden;
			pq.push( Orden );
			dq.push_back( make_pair( Orden, Pos ) ); // Pareja Orden y posicion 
			Pos++;
		}

		int ans = 0;
		bool flag = true;
        
		while( !flag ){
			Top = pq.top();
			pq.pop();
			while( dq.front().first != Top ){
				OrdenTemp = dq.front().first; // Front del orden -> prioridad
				// cout<< tmpF;
				PosTemp = dq.front().second; // Front de posición
				// cout<< tmpS
				dq.pop_front();
				dq.push_back( make_pair( OrdenTemp, PosTemp ) );
			}
			if( dq.front().second == Tpos ){
				ans++;
				flag = false;
			}else{
				dq.pop_front();
				ans++;
			}

		}

		cout<< ans <<endl;
	}
	return 0;
}