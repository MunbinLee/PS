#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

typedef pair<int, pair<int, int>> p;

int ans, n, m;
int parent[50001];
array<p, 200000> edges; // 가중치, 출발점, 도착점

void input() {
  ans = 0;

  scanf("%d\n%d", &n, &m);

  int s, e, c;
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &s, &e, &c);
    edges[i] = {c, {s, e}};
  }
  sort(edges.begin(), edges.begin() + m);
}

void setParent() {
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
  }
}

int getParent(int i) {
  if (parent[i] == i) return i;
  return parent[i] = getParent(parent[i]);
}

void unionParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);
  if (a < b) parent[b] = a;
  else parent[a] = b;
}

bool isCycle(int a, int b) {
  a = getParent(a);
  b = getParent(b);
  if (a == b) return true;
  else return false;
}

void solve() {
  setParent();

  for (int i = 0; i < m; i++) {
    if (!findParent(edges[i].second.first, edges[i].second.second)) {
      ans += edges[i].first;
      unionParent(edges[i].second.first, edges[i].second.second);
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);

  for (int c = 1; c <= t; c++) {
    input();
    solve();
    printf("#%d %d\n", c, ans);
  }
  return 0;
}
