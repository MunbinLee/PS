#include <iostream>
#include <vector>

using namespace std;

int g, p, cnt;
vector<int> v;
vector<int> parent;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> g >> p;
  parent.resize(g + 1);
  for (int i = 0; i <= g; i++) {
    parent[i] = i;
  }
  v.resize(p);
  for (int &i: v) {
    cin >> i;
  }
}

int getParent(int i) {
  if (parent[i] == i) return i;
  return parent[i] = getParent(parent[i]);
}

void solve() {
  for (int i: v) {
    i = getParent(i);
    if (i == 0) return;
    parent[i] = getParent(i - 1);
    cnt++;
  }
}

int main() {
  input();
  solve();
  cout << cnt;
  return 0;
}
