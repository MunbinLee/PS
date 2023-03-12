#include <iostream>

using namespace std;

int n, m;
int parent[500000];

void initParent() {
  for (int i = 0; i < n; i++) {
    parent[i] = i;
  }
}

int getParent(int a) {
  if (parent[a] == a) return a;
  return parent[a] = getParent(parent[a]);
}

bool findParent(int a, int b) {
  int pa = getParent(a);
  int pb = getParent(b);
  return (pa == pb);
}

void unionParent(int a, int b) {
  // assert(b > a);
  int pa = getParent(a);
  int pb = getParent(b);
  parent[pb] = pa;
}

int solve() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  initParent();
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    if (findParent(a, b)) return i;
    unionParent(a, b);
  }
  return 0;
}

int main() {
  cout << solve();
  return 0;
}
