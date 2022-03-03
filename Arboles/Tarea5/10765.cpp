#include <bits/stdc++.h>

using namespace std;

int n, t;
vector<vector<int> > adj(50000);
int visitado[50000];
int low[50000];
int padre[50000];
set<int> apNodos;

void apAux(int);

void apAux(int v, int fa ){

  int w, numHijos = 0;
  visitado[v] = low[v] = ++t;

  for(int i = 0; i < adj[v].size(); i++){
    w = adj[v][i];
    if(visitado[w] == -1){
      numHijos++;
      padre[w] = v;
      apAux(w);
      low[v] = min(low[v], low[w]);

      //verificar si es un punto de articulacion
      if(padre[v] != -1 && low[w] >= visitado[v])
	apNodos.insert(v);
    }
    else if(w != padre[v])
      low[v] = min(low[v], visitado[w]);
  }

  if(padre[v] == -1 && numHijos > 1)
    apNodos.insert(v);
}

void ap(){
  int i;

  for(i = 0; i < n; i++)
    low[i] = visitado[i] = padre[i] =-1;

  for(i = 0; i < n; i++)
    if(visitado[i] == -1)
      apAux(i, -1 );
}


int main(){
    int m, a, b;
    while(  scanf( "%d %d", &n, &m ) && ( n || m ) ){

        while( scanf( "%d %d", &a, &b ) && ( a != -1 && b != -1 ) ){
            adj[ a ].push_back( b );
            adj[ b ].push_back( a );
        }      
    

    ap();
    if(apNodos.size() >= 0){
        for(set<int>::iterator it = apNodos.begin(); it != apNodos.end(); ++it)
            cout << " " << *it<<endl;
    }
    }

    return 0;
}