#include <bits/stdc++.h>
#define INF (1<<29)

using namespace std;

int n, p, mp;

void dijkstra( vector<pair<int, int>> adj[ ], vector<int>& dist, int s, int t ){
	priority_queue< pair<int, int> , vector<pair<int, int> >, greater<pair<int, int> > > nodo;

	dist[ s ] = 0;
	nodo.push(pair<int, int>(0, s));

	while(not nodo.empty())
	{
		int u = nodo.top().second;
		int d = nodo.top().first;

		nodo.pop();
		if( dist[u] < d ){
		    continue;
        }
		for(int i = 0; i < adj[u].size(); ++i){
			pair<int, int> v = adj[u][i];
			if(dist[u] + v.second < p and dist[u] + v.second < dist[v.first]){
				dist[v.first] = dist[u] + v.second;
				nodo.push(pair<int, int>(dist[v.first], v.first));
			}
		}
	}
}

int main(){
	int casos;
	cin >> casos;

	while( casos > 0 ){
		int m, s, t;
		cin >> n >> m >> s >> t >> p;
		++n;
		vector<pair<int, int>> v1[ n ];
		vector<pair<int, int>> v2[ n ];

		for(int i = 0; i < m; ++i){
			int u, v, c;
			cin >> u >> v >> c;

			v1[ u ].push_back( make_pair( v, c ) );
			v2[ v ].push_back( make_pair( u, c ) );
		}

		mp = -1;
		vector<int> d1( n, INF );
		vector<int> d2( n, INF );

		dijkstra( v1, d1, s, t );
		dijkstra( v2, d2, t, s );
		
		for( int j = 1; j < n; ++j ){
			for( int i = 0; i < v1[ j ].size(); ++i ){
				pair<int, int> v = v1[ j ][ i ];

				if( d1[ j ] + v.second + d2[ v.first ] <= p ){
					mp = max( mp, v.second );	
				}
			}
		}

		cout<<mp<<endl;
	casos = casos -1;
	}
	return 0;
}