#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <map>

using namespace std;

void bellMan_Ford(map <pair <int, int>, int> & edges, vector <int> & tolerance);

int main(void)
{
	int T = 0;
	cin >> T;
	int tcounter = 0;

	while(T--){
		++tcounter;

		int n = 0;
		cin >> n;

		map <string, int> cities;
		
		for(int i = 0; i < n; ++i){
			string city;
			cin >> city;
			cities[city] = i;
		}

		map < pair <int, int>, int> edges;

		int m = 0;
		cin >> m;

		for(int i = 0; i < m; ++i){
			string city1, city2;
			int cost;

			cin >> city1 >> city2 >> cost;

			int code1 = cities[city1];
			int code2 = cities[city2];

			if(edges.find(make_pair(code1, code2)) != edges.end())
				edges[make_pair(code1, code2)] = min(edges[make_pair(code1, code2)], cost);
			else
				edges[make_pair(code1, code2)] = cost;
		}

		vector <int> tolerance(n, INT_MAX);
		bellMan_Ford(edges, tolerance);

		cout << "Scenario #" << tcounter << endl;

		int query = 0;
		cin >> query;

		for(int i = 0; i < query; ++i){
			int max_tolerance;
			cin >> max_tolerance;

			max_tolerance = min(max_tolerance, n - 2);

			if(tolerance[max_tolerance] != INT_MAX)
				cout << "Total cost of flight(s) is $" << tolerance[max_tolerance] << endl;
			else
				cout << "No satisfactory flights" << endl;
		}

		if(T)
			cout << endl;
	}
	return 0;
}


void bellMan_Ford(map <pair <int, int>, int> & edges, vector <int> & tolerance)
{
	int n = tolerance.size();//number of nodes in the Graph
	vector <int> cost(n, INT_MAX);
	cost[0] = 0;

	for(int i = 0; i < n - 1; ++i){
		for(auto edge = edges.rbegin(); edge != edges.rend(); ++edge){
			int u = edge->first.first;
			int v = edge->first.second;
			int value = edge->second;

			if(cost[u] != INT_MAX)
				cost[v] = min(cost[u] + value, cost[v]);
		}

		tolerance[i] = min(i > 0 ? tolerance[i - 1] : INT_MAX, cost[n - 1]);
	}

	return;
}


/////////////////////////////////////7

#include <cstdio>
#include <map>
#include <iostream>
#define INF 100000000


using namespace std;

int totalnode,totaledge;
struct EDGES
{
    int start,finish,weight;
}edge[1010];

int d[110];
int result[110];
map <string,int> ind;


void bellmanford(int source,int des,int s)
{
        for (int i = 0; i < 110; ++i)
        {
            d[i] = INF;
            result[i]=INF;
        }

        d[source] = result[source]= 0;


        for (int i = 0; i <= s; ++i)
        {
            for (int j = 0; j < totaledge; ++j)
            {
                    if (result[edge[j].start] + edge[j].weight < d[edge[j].finish])
                                d[edge[j].finish] = result[edge[j].start] + edge[j].weight;
            }

            for (int j=0;j<totalnode;++j)
            {
                result[j]=d[j];
            }

        }


        if (d[des]!=INF)
            printf("Total cost of flight(s) is $%d\n",d[des]);
        else
            printf("No satisfactory flights\n");
}


int main()
{

    freopen("in.txt","r",stdin);

    int test;

    scanf("%d",&test);

    for (int m=1;m<=test;++m)
    {

        ind.clear();

        if (m!=1)printf("\n");

        scanf("%d",&totalnode);

        string a,b;
        for (int i=0;i<totalnode;++i)
        {
            cin>>a;
            ind[a]=i;
        }

        scanf("%d",&totaledge);

        int n;
        for (int i=0;i<totaledge;++i)
        {
            cin>>a>>b>>n;
            edge[i].start=ind[a];
            edge[i].finish=ind[b];
            edge[i].weight=n;
        }

        printf("Scenario #%d\n",m);

        int step;
        scanf("%d",&n);
        while (n--)
        {
            scanf("%d",&step);
            bellmanford(ind["Calgary"],ind["Fredericton"],step);
        }
    }
    return 0;
}