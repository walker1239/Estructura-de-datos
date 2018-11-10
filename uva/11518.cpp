#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
#define tam 10000

using namespace std;

vector <int> grafo[tam];
int total;
bool visitado[tam];

void dfs(int u)
{
	if (visitado[u])
	{
		return;
	}
	total++;
	visitado[u] = true;
	for(auto v:grafo[u]){		
		dfs(v);
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
		cout<<endl;
	}
	return 0;
}