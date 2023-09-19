#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  v = vector<int>(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
}

void solve() {
  int money = 0;
  while (n) {
    int idx = 0;
    double mx = 0;
    for (int i = 1; i <= n; i++) {
      if (i > n) continue;
      double tmp = (double) v[i] / i;
      if (tmp > mx) {
        mx = tmp;
        idx = i;
      }
    }
    n -= idx;
    money += v[idx];
  }
  cout << money;
}

int main() {
  input();
  solve();
  return 0;
}
