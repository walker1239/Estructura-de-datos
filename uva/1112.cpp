#include <stdio.h>
#include <queue>
#include <string.h>
#include <iostream>
using namespace std;
struct edge {
    int to, v;
    edge(int a, int b){
        to=a;
        v=b;
    }
};

vector<edge> g[105];
priority_queue<int> Q;
int dist[105], inq[105];

void Dijkstra(){
    while(!Q.empty()) {
        int tn = Q.top();
        Q.pop(), inq[tn] = 0;
        for(vector<edge>::iterator it = g[tn].begin();
            it != g[tn].end(); it++) {
            if(dist[it->to] > dist[tn] + it->v) {
                dist[it->to] = dist[tn] + it->v;
                if(inq[it->to] == 0) {
                    inq[it->to] = 1;
                    Q.push(it->to);
                }
            }
        }
    }
}

int main() {
    int testcase;
    int n, m, st, time;
    int x, y, v;
    cin>>testcase;
    while(testcase--) {
        cin>>n>>st>>time>>m;
        
        while(m--) {
            cin>>x>>y>>v;
            g[y].push_back(edge(x, v));
        }
        dist[105], inq[105] = {};
        memset(dist, 63, sizeof(dist));
        dist[st] = 0;
        
        Q.push(st);
        Dijkstra();
        int ret = 0;
        for(int i = 0; i <= n; i++ )
            if(dist[i] <= time)
                ret++;
        cout<<ret<<endl;
        if(testcase)
            cout<<endl;
    }
    return 0;
}
 