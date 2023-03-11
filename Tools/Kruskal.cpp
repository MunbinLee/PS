#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> tp; // 가중치, 출발점, 도착점

int v, e;
vector<tp> edge;
vector<int> parent;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> v >> e;
  parent.resize(v + 1);
  for (int i = 1; i <= v; i++) {
    parent[i] = i;
  }

  edge.resize(e);
  for (auto &i: edge) {
    int a, b, c;
    cin >> a >> b >> c;
    i = {c, a, b};
  }
  sort(edge.begin(), edge.end());
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

bool isParentSame(int a, int b) {
  a = getParent(a);
  b = getParent(b);
  return (a == b);
}

int solve() {
  int res = 0;
  for (auto i: edge) {
    auto [cost, start, end] = i;
    if (!isParentSame(start, end)) {
      res += cost;
      unionParent(start, end);
    }
  }
  return res;
}

int main() {
  input();
  cout << solve();
  return 0;
}
