#include <iostream>
#include <queue>
#include <vector>

#define INF INT32_MAX
using namespace std;

int n, k;
vector<int> dist;
vector<vector<pair<int, int>>> edges;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int e;
  cin >> n >> e >> k;
  vector<pair<int, int>> edge;
  edges = vector(n + 1, edge);

  while (e--) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].emplace_back(v, w);
  }
}

void dijkstra() {
  dist = vector<int>(n + 1, INF);
  dist[k] = 0;

  priority_queue<pair<int, int>> pq;
  pq.emplace(0, k);

  while (!pq.empty()) {
    auto [cost, cur] = pq.top();
    cost *= -1;
    pq.pop();

    for (auto i: edges[cur]) {
      auto [next, nCost] = i;
      if (dist[next] <= cost + nCost) continue;
      dist[next] = cost + nCost;
      pq.emplace(-dist[next], next);
    }
  }
}

void output() {
  for (int i = 1; i <= n; i++) {
    if (dist[i] == INF) cout << "INF\n";
    else cout << dist[i] << '\n';
  }
}

int main() {
  input();
  dijkstra();
  output();
  return 0;
}
