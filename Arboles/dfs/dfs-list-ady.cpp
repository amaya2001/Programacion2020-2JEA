#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

int MAX = 10000;
int n, t = 0;
vector<vector<int>> adj(MAX);
vector<int> visitado(MAX), pred(MAX), f(MAX), d(MAX);

// 0 = no visitado, 1 = visitado pero no completado, 2 = completado
void dfsAux(int w){
  int u, i;
  //d[v] = ++t;
  visitado[w] = 1;
  printf("%d\n", w);

  for(i = 0; i < adj[w].size(); ++i){
    u = adj[w][i];
    if(visitado[u] == 0){
      //pred[u] = w;
      dfsAux(u);
    }
  }

  //visitado[v] = 2;
  //f[v] = ++t;
}

void dfs(){
  int i;
  
  for(i = 0; i < n; ++i){
    visitado[i] = 0;
    //pred[i] = -1;
  }
  
  for(i = 0; i < n; ++i){
    if(visitado[i] == 0)
      dfsAux(i);
  }
}

int main(){
  int m, u, v, i, j;
  map<string, int> id;

  cin >> n >> m;

  for(i = 0; i < n; ++i){
    cin >> u;
    adj[i].resize(u);
    for(j = 0; j < u; ++j)
      cin >> adj[i][j];
  }

  printf("Grafo\n");
  for(i = 0; i < n; ++i){
    printf("Nodo %d:", i);
    for(j = 0; j < adj[i].size(); ++j)
      printf(" %d", adj[i][j]);
    printf("\n");
  }

  printf("Recorrido en profundidad grafo:\n");
  dfs();
  printf("Predecesores:\n");
  for(i = 0; i < n; ++i)
    printf("El predecesor de %d es %d\n", i, pred[i]);

  return 0;
}
