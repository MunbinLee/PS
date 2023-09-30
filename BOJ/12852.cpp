#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> calc;
vector<int> path;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  calc.assign(n + 1, -1);
  path.resize(n + 1);
}

void solve() {
  calc[1] = 0;
  for (int i = 2; i <= n; i++) {
    calc[i] = calc[i - 1] + 1;
    path[i] = i - 1;
    if (i % 2 == 0 && calc[i / 2] + 1 < calc[i]) {
      calc[i] = calc[i / 2] + 1;
      path[i] = i / 2;
    }
    if (i % 3 == 0 && calc[i / 3] + 1 < calc[i]) {
      calc[i] = calc[i / 3] + 1;
      path[i] = i / 3;
    }
  }
}

void output() {
  cout << calc[n] << '\n' << n << ' ';
  while (path[n]) {
    cout << path[n] << ' ';
    n = path[n];
  }
}

int main() {
  input();
  solve();
  output();
  return 0;
}
