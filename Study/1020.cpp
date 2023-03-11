#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 10005;
const int INF = 987654321;

vector<pair<int, int>> adj[MAXN];
int dist[MAXN];     // 최단 거리
int cnt[MAXN];      // 최단 경로 개수
bool visited[MAXN]; // 방문 여부

int dijkstra(int s, int t, int n) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  fill(dist, dist + n, INF);
  fill(cnt, cnt + n, 0);
  pq.emplace(0, s);
  dist[s] = 0;
  cnt[s] = 1;
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    if (visited[u]) continue;
    visited[u] = true;
    for (auto v: adj[u]) {
      int w = v.first, len = v.second;
      if (dist[u] + len < dist[w]) {
        dist[w] = dist[u] + len;
        cnt[w] = cnt[u];
        pq.emplace(dist[w], w);
      } else if (dist[u] + len == dist[w]) {
        cnt[w] += cnt[u];
      }
    }
  }
  return cnt[t];
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].emplace_back(v, w);
  }
  int s, t;
  cin >> s >> t;
  cout << dijkstra(s, t, n) << '\n';
  return 0;
}