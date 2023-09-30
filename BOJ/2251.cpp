#include <iostream>
#include <vector>

using namespace std;

int n, m;
bool doesExist[32001];
vector<int> req[32001];

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    req[b].emplace_back(a);
  }
}

void solveProblem(int i) {
  for (int r: req[i]) {
    if (doesExist[r]) continue;
    addStudent(r);
  }
  doesExist[i] = true;
  cout << i << ' ';
}

void solve() {
  for (int i = 1; i <= n; i++) {
    if (doesExist[i]) continue;
    addStudent(i);
  }
}

int main() {
  input();
  solve();
  return 0;
}
