
#include <iostream>
#include <queue>
using namespace std;


const long long int inf = 1e12;

struct edge {
  int to;
  long long int len, cost;
  bool operator < (const edge & e) const {
    if (len == e.len)
      return cost > e.cost;
    return len > e.len;
  }
};


priority_queue<edge> q;
vector<edge> best;
vector<long long int > cost;

void Dijkstra(vector<vector<edge>> g){
    while (!q.empty()) {
      edge s = q.top();
      q.pop();

      int node = s.to;

      if (s< best[node]) continue;

      for (auto e : g[node]) {
        int to = e.to;
        edge extra = {to, s.len + e.len, e.cost};
        if (best[to]<extra) {
          best[to] = extra;
          cost[to] = e.cost;
          q.push(extra);
        }
      }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<edge>> g(n);
  for (int i = 0; i < m; i++) {
    int A, B;
    long long int l, c;
    cin >> A >> B >> l >> c;
    A--;
    B--;
    g[A].push_back({B, l, c});
    g[B].push_back({A, l, c});
  }

  
  q.push({0, 0, 0});

  
  best.reserve(n);
  best.assign(n,{0,inf,inf});
  
  best[0] = {0, 0, 0};

  
  cost.reserve(n);
  cost.assign(n,0);

  Dijkstra(g);

  long long int total = 0;
  for (int i = 0; i < n; i++) {
    total += cost[i];
  }
  cout << total << endl;

  return 0;
}