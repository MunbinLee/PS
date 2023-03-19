#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, a, b, s, e, r, q_start, q_end;
  int path[10001];
  pair<int, int> q[10001];
  bool visited[10001];
  vector<int> edge[10001];
  cin >> n >> m;
  while (m--) {
    cin >> a >> b;
    edge[a].emplace_back(b);
    edge[b].emplace_back(a);
  }
  cin >> s >> e;
  for (auto &i: edge) {
    sort(i.begin(), i.end());
  }
  q_start = 0;
  q_end = 0;
  q[q_end++] = {s, 0};
  r = 0;
  while (true) {
    auto [cur, dist] = q[q_start++];
    if (cur == e) {
      r += dist;
      break;
    }
    for (auto i: edge[cur]) {
      if (visited[i]) continue;
      visited[i] = true;
      path[i] = cur;
      q[q_end++] = {i, dist + 1};
    }
  }
  memset(visited, false, 10001);
  int p = path[e];
  while (p != s) {
    visited[p] = true;
    p = path[p];
  }
  q_start = 0;
  q_end = 0;
  q[q_end++] = {e, 0};
  while (true) {
    auto [cur, dist] = q[q_start++];
    if (cur == s) {
      r += dist;
      break;
    }
    for (auto i: edge[cur]) {
      if (visited[i]) continue;
      visited[i] = true;
      path[i] = cur;
      q[q_end++] = {i, dist + 1};
    }
  }
  cout << r;
  return 0;
}
