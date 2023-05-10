#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pr;

const int INF = 987654321;
int n, m, x;
vector<vector<pr>> path[2]; // path[0][s]{t,e} s-e 비용, path[1][e]{t,s} 역방향 비용
vector<int> dist[2]; // dist[0][s] s-x 비용, dist[1][s] x-s 비용

void input() {
  cin >> n >> m >> x;
  path[0].resize(n + 1);
  path[1].resize(n + 1);
  dist[0].resize(n + 1, INF);
  dist[1].resize(n + 1, INF);
  while (m--) {
    int s, e, t;
    cin >> s >> e >> t;
    path[0][s].emplace_back(t, e);
    path[1][e].emplace_back(t, s);
  }
}

void dijkstra(int r) {
  dist[r][x] = 0;
  priority_queue<pr, vector<pr>, greater<>> pq;
  pq.emplace(0, x);

  while (!pq.empty()) {
    auto [cost, cur] = pq.top();
    pq.pop();
    if (cost > dist[r][cur]) continue;
    for (auto &p: path[r][cur]) {
      auto [ncost, next] = p;
      ncost += cost;
      if (ncost >= dist[r][next]) continue;
      dist[r][next] = ncost;
      pq.emplace(ncost, next);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  input();
  dijkstra(1);
  dijkstra(0);

  int maxTime = 0;
  for (int i = 1; i <= n; i++) {
    int time = dist[0][i] + dist[1][i];
    maxTime = max(maxTime, time);
  }
  cout << maxTime;
  return 0;
}
