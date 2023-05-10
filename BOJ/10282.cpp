#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pr;

const int INF = 987654321;

void solve() {
  int n, d, c;
  cin >> n >> d >> c;
  vector<vector<pr>> path(n + 1); // path[s] = {t, e}
  vector<int> dist(n + 1, INF); // dist[e] = c~e 비용
  dist[c] = 0;

  while (d--) {
    int a, b, s;
    cin >> a >> b >> s;
    path[b].emplace_back(s, a);
  }

  priority_queue<pr, vector<pr>, greater<>> pq;
  pq.emplace(0, c);
  while (!pq.empty()) {
    auto [cost, cur] = pq.top();
    pq.pop();
    for (auto &p: path[cur]) {
      auto [ncost, next] = p;
      ncost += cost;
      if (ncost >= dist[next]) continue;
      dist[next] = ncost;
      pq.emplace(ncost, next);
    }
  }

  int cnt = 0;
  int time = 0;
  for (int i = 1; i <= n; i++) {
    if (dist[i] == INF) continue;
    cnt++;
    time = max(time, dist[i]);
  }
  cout << cnt << ' ' << time << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
