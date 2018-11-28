#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 100000
int N,n,m,S,T,u,v,w;
#define INF 1e9
pair<int,int> edge;
vector <pair<int,int> > G[MAX];
priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int ,int>>> Q;
int d[MAX];
bool change;

void dijkstra (int src)
{
    edge.first=0;
    edge.second=src;
    Q.push(edge);
    d[src]=0;
    change = false;
    int i;
    while(!Q.empty())
    {
        u=Q.top().second;
        w=Q.top().first;
        Q.pop();

        for( i=0;i<G[u].size();i++)
        {
            v=G[u][i].first;
            w=G[u][i].second;
            if(d[v]>d[u]+w)
            {
                if(v==T) change =true;

                d[v]=d[u]+w;

                edge.first=d[v];
                edge.second=v;
                Q.push(edge);
            }

        }
    }
}



int main()
{
    cin >> N;
    int i;
    for(i=1;i<=N;i++)
    {
        cin>>n>>m>>S>>T;

        for(int j=0;j<m;j++)
        {
            cin>>u>>v>>w;
            edge.first=v;
            edge.second=w;
            G[u].push_back(edge);
            edge.first=u;
            edge.second=w;
            G[v].push_back(edge);

        }
        for(int k=0;k<MAX;k++)
            d[k]=INF;

        dijkstra( S);
        printf("Case #%d: ",i);
        if(change)
            cout<<d[T]<<endl;
        else
            cout<<"unreachable"<<endl;
        for(int l=0;l<MAX;l++)
            G[l].clear();


    }


    return 0;
}