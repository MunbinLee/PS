#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int r;
int path[10001];
pair<int, int> q[9001];
bool visited[10001];
vector<int> edge[10001];

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, a, b;
  cin >> n >> m;
  while (m--) {
    cin >> a >> b;
    edge[a].emplace_back(b);
    edge[b].emplace_back(a);
  }
  for (auto &i: edge) {
    sort(i.begin(), i.end());
  }
}

void bfs(int start, int end) {
  int q_start = 0;
  int q_end = 0;
  q[q_end++] = {start, 0};
  while (true) {
    auto [cur, dist] = q[q_start++];
    if (cur == end) {
      r += dist;
      return;
    }
    for (auto i: edge[cur]) {
      if (visited[i]) continue;
      visited[i] = true;
      path[i] = cur;
      q[q_end++] = {i, dist + 1};
    }
  }
}

void solve() {
  int s, e;
  cin >> s >> e;
  bfs(s, e);
  memset(visited, false, 10001);
  int p = path[e];
  while (p != s) {
    visited[p] = true;
    p = path[p];
  }
  bfs(e, s);
  cout << r;
}

int main() {
  input();
  solve();
  return 0;
}
