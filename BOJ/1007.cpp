#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector<pair<int, int>> v;

void input() {
  cin >> n;
  v.resize(n);
  for (auto &i: v) {
    cin >> i.first >> i.second;
  }
}

void solve() {
  double res = 300000;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int x = v[i].first - v[j].first;
      int y = v[i].second - v[j].second;
      double dist = sqrt((double) x * x + (double) y * y);
      if (dist < res) res = dist;
    }
  }
  cout.precision(7);
  cout << fixed << res << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    input();
    solve();
  }
  return 0;
}
