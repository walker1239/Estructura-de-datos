#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
#define tam 10005

using namespace std;

vector <int> grafo[tam];
int total;
bool visitado[tam];

void dfs(int u)
{
	total++;
	visitado[u] = true;
	for(int v = 0; v < grafo[u].size(); v++){
		if(!visitado[grafo[u][v]])			
			dfs(grafo[u][v]);
	}
}

int main()
{
	int T, n, m, l, x, y, z;

	cin>>T;
	while(T--)
	{
		cin>>n>>m>>l;
		while(m--){
			cin>>x>>y;
			grafo[x].push_back(y);
		}
		while(l--){			
			cin>>z;
			if(!visitado[z])		
				dfs(z);
		}
		
		cout<<total;
		total = 0;
		memset(visitado, 0, sizeof(visitado));
		for(int i = 0; i < n; i++){
			grafo[i].clear();
		}
	}
	return 0;
}