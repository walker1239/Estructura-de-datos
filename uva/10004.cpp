//usuario walker1239

#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#define tam  201
using namespace std;

queue<int>q;
vector<int>v[tam];
int color[tam],flag;

void bfs()
{
    int f,l;
    while(!q.empty())
    {
        f=q.front();
        q.pop();
        l=v[f].size();
        for(int i=0; i<l; i++)
        {
            if(color[v[f][i]]==0)
            {
                if(color[f]==1)
                    color[v[f][i]]=2;
                else
                    color[v[f][i]]=1;
                q.push(v[f][i]);

            }
            else if(color[v[f][i]]==color[f])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            break;
    }
    return;
}


int main()
{
    int n1,n2,n,edge;
    while(cin>>n&&n)
    {
        cin>>edge;
        memset(color,0,sizeof(color));
        flag=0;
        for(int i=0; i<edge; i++)
        {
            cin>>n1>>n2;
            v[n1].push_back(n2);
            v[n2].push_back(n1);
        }
        color[0]=1;
        q.push(0);
        bfs();
        if(flag==1)
            cout<<"NOT BICOLORABLE."<<endl;
        else cout<<"BICOLORABLE."<<endl;;
        for(int i=0; i<=n; i++)
            v[i].clear();
             while(!q.empty())
                q.pop();
    }
    return 0;
}
