#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;
typedef pair<int, int> pr;
typedef long long int ll;

int n;
vector<pr> v;

int bitCount(int visited) {
  return __builtin_popcount(visited);
}

ll calc(int visited) {
  if (bitCount(visited) != n / 2) return INT64_MAX;

  ll x = 0;
  ll y = 0;
  for (int i = 0; i < n; i++) {
    if (visited & (1 << i)) {
      x += v[i].first;
      y += v[i].second;
    } else {
      x -= v[i].first;
      y -= v[i].second;
    }
  }
  return x * x + y * y;
}

double dfs(int idx, int visited) {
  if (idx == n) return calc(visited);

  return min(dfs(idx + 1, visited), dfs(idx + 1, visited + (1 << idx)));
}

void solve() {
  cin >> n;
  v.resize(n);
  for (auto &[x, y]: v) {
    cin >> x >> y;
  }

  ll dist2 = dfs(0, 0);
  double dist = sqrt(dist2);
  cout << fixed << setprecision(6) << dist << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
