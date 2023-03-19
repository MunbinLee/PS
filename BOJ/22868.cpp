#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, s, e;
vector<bool> visited;
vector<int> path;
vector<vector<bool>> edge;
queue<pair<int, int>> q; // 위치, 경로길이

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  visited.resize(n + 1);
  path.resize(n + 1);
  edge.resize(n + 1, vector<bool>(n + 1));
  while (m--) {
    int a, b;
    cin >> a >> b;
    edge[a][b] = true;
    edge[b][a] = true;
  }
  cin >> s >> e;
}

int bfs(int start, int end) {
  visited[start] = true;
  q.emplace(start, 0);
  while (!q.empty()) {
    auto [cur, dist] = q.front();
    q.pop();
    if (cur == end) {
      return dist;
    }
    for (int i = 1; i <= n; i++) {
      if (visited[i]) continue;
      if (!edge[cur][i]) continue;
      visited[i] = true;
      path[i] = cur;
      q.emplace(i, dist + 1);
    }
  }
}

void solve() {
  int r1 = bfs(s, e);

  while (!q.empty()) q.pop();
  for (int i = 1; i <= n; i++) visited[i] = false;
  int p = path[e];
  while (p) {
    visited[p] = true;
    p = path[p];
  }
  visited[s] = false;
  int r2 = bfs(e, s);
  cout << r1 + r2;
}

int main() {
  input();
  solve();
  return 0;
}
