#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pr;

const int INF = 987654321;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<vector<pr>> edges(n + 1); // edges[s] = {c, e}
  vector<int> dist(n + 1, INF); // dist[i] = start ~ i 비용

  while (m--) {
    int s, e, c;
    cin >> s >> e >> c;
    edges[s].emplace_back(c, e);
  }

  int start, end;
  cin >> start >> end;

  priority_queue<pr, vector<pr>, greater<>> pq;
  pq.emplace(0, start);
  while (!pq.empty()) {
    auto [cost, cur] = pq.top();
    pq.pop();
    if (cost > dist[cur]) continue;
    for (auto [nCost, next]: edges[cur]) {
      int sumCost = cost + nCost;
      if (sumCost >= dist[next]) continue;
      dist[next] = sumCost;
      pq.emplace(sumCost, next);
    }
  }

  cout << dist[end];
  return 0;
}