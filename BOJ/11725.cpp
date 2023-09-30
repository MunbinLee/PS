#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n;
vector<int> parents;
vector<set<int>> edges;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  parents = vector<int>(n + 1);
  edges = vector<set<int>>(n + 1, set<int>());

  for (int i = 0; i < n - 1; i++) {
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;

    edges[tmp1].emplace(tmp2);
    edges[tmp2].emplace(tmp1);
  }
}

void solve(int key) {
  for (auto it = edges[key].begin(); it != edges[key].end();) {
    int tmp = *it;
    parents[tmp] = key;
    edges[tmp].erase(key);
    it = edges[key].erase(it);
    solve(tmp);
  }
}

void output() {
  for (int i = 2; i <= n; i++) {
    cout << parents[i] << '\n';
  }
}

int main() {
  input();
  solve(1);
  output();
  return 0;
}
