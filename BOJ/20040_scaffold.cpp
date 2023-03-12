#include <iostream>

using namespace std;

int n, m;
int parent[500000];
int parent2[500000];
pair<int, int> arr[1001];

void initParent() {
  for (int i = 0; i < n; i++) {
    parent[i] = i;
  }
}

void initParent2() {
  for (int i = 0; i < n; i++) {
    parent2[i] = i;
  }
}

int getParent(int a) {
  if (parent[a] == a) return a;
  return parent[a] = getParent(parent[a]);
}

int getParent2(int a) {
  if (parent2[a] == a) return a;
  return parent2[a] = getParent2(parent2[a]);
}

bool findParent(int a, int b) {
  int pa = getParent(a);
  int pb = getParent(b);
  return (pa == pb);
}

bool findParent2(int a, int b) {
  int pa = getParent2(a);
  int pb = getParent2(b);
  return (pa == pb);
}

void unionParent(int a, int b) {
  // assert(b > a);
  int pa = getParent(a);
  int pb = getParent(b);
  parent[pb] = pa;
}

void unionParent2(int a, int b) {
  int pa = getParent2(a);
  int pb = getParent2(b);
  if (pa < pb) parent2[pb] = pa;
  else parent2[pa] = pb;
}

void input() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    arr[i].first = a;
    arr[i].second = b;
  }
}

int solve() {
  initParent();
  for (int i = 1; i <= m; i++) {
    int a = arr[i].first;
    int b = arr[i].second;
    if (findParent(a, b)) return i;
    unionParent(a, b);
  }
  return 0;
}

int solve2() {
  initParent2();
  for (int i = 1; i <= m; i++) {
    int a = arr[i].first;
    int b = arr[i].second;
    if (a > b) swap(a, b);
    if (findParent2(a, b)) return i;
    unionParent2(a, b);
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int nn = 100;
  while (nn--) {
    input();
//    cout << solve() << ' ' << solve2() << '\n';
    int r1 = solve();
    int r2 = solve2();
    if (r1 != r2) cout << r1 << ' ' << r2 << '\n';
  }
  return 0;
}
