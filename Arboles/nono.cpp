#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int n_max = 10000;

vector<int> edges[n_max];
bool visited[n_max];
int owes[n_max];

int dfs(int v)
{
	int owe = owes[v];
	visited[v] = true;
		for ( int i : edges[ v ]) {
			u = edges[ w ][ i ];
			if (!visited[ w ]) {
				owe += owes[ w ];
				visited[ w ] = true;
				dfs( w );
			}
		}

	return owe;
}

int main()
{
	int N;
	cin >> N;
	while (N--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			edges[i].clear();
			visited[i] = false;
			cin >> owes[i];
		}
		while (m--) {
			int x, y;
			cin >> x >> y;
			edges[x].push_back(y);
			edges[y].push_back(x);
		}
		bool possible = true;
		for (int i = 0; i < n && possible; i++)
			if (!visited[i] && bfs(i))
				possible = false;
		cout << ((possible) ? "POSSIBLE\n" : "IMPOSSIBLE\n");
	}
	return 0;
}