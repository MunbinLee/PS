#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pr;

const int INF = 987654321;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int v;
  cin >> v;
  vector<vector<pr>> path(v + 1);
  for (int i = 0; i < v; i++) {
    int start, end, cost;
    cin >> start >> end;
    while (end != -1) {
      cin >> cost;
      path[start].emplace_back(cost, end);
      cin >> end;
    }
  }

  vector<vector<int>> dist(v + 1, vector<int>(v + 1, INF));
  priority_queue<pr, vector<pr>, greater<>> pq;
  for (int i = 1; i <= v; i++) {
    pq.emplace(0, i);
  }

  while (!pq.empty()) {
    auto [cost, cur] = pq.top();
    pq.pop();
    for (auto [ncost, next]: path[cur]) {
      int sumCost = ncost + cost;
      if (sumCost >= dist[cur][next]) continue;
      dist[cur][next] = sumCost;
      pq.emplace(sumCost, next);
    }
  }

  int maxDist = 0;
  for (int i = 1; i + 1 <= v; i++) {
    for (int j = i + 1; j <= v; j++) {
      if (dist[i][j] == INF) continue;
      maxDist = max(maxDist, dist[i][j]);
    }
  }

  cout << maxDist;
  return 0;
}