#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

typedef pair<double, pair<int, int>> p;

int edgeCnt, n;
int x[1000];
int y[1000];
int parent[1000];
double ans, e;
array<p, 499500> edges; // 가중치, 출발점, 도착점

void input() {
  ans = 0;
  edgeCnt = 0;

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &y[i]);
  }
  scanf("%lf", &e);
}

void setParent() {
  for (int i = 0; i < n; i++) {
    parent[i] = i;
  }
}

double getDist(int i, int j) {
  int dx = x[i] - x[j];
  int dy = y[i] - y[j];
  return (double) dx * dx + (double) dy * dy;
}

void addEdges() {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      edges[edgeCnt++] = {getDist(i, j), {i, j}};
    }
  }
  sort(edges.begin(), edges.begin() + edgeCnt);
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

bool findParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);
  if (a == b) return true;
  else return false;
}

void solve() {
  setParent();
  addEdges();

  for (int i = 0; i < edgeCnt; i++) {
    if (!findParent(edges[i].second.first, edges[i].second.second)) {
      ans += edges[i].first;
      unionParent(edges[i].second.first, edges[i].second.second);
    }
  }
  ans *= e;
}

int main() {
  int t;
  scanf("%d", &t);

  for (int c = 1; c <= t; c++) {
    input();
    solve();
    printf("#%d %.lf\n", c, ans);
  }
  return 0;
}
