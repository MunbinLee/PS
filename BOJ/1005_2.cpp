#include <iostream>
#include <vector>

using namespace std;

int n, k, w;
vector<int> buildTime, buildDate;
vector<vector<int>> required;

void input() {
  cin >> n >> k;

  buildTime.resize(n + 1);
  buildDate.assign(n + 1, -1);
  required.assign(n + 1, {});

  for (int i = 1; i <= n; i++) {
    cin >> buildTime[i];
  }

  while (k--) {
    int x, y;
    cin >> x >> y;
    required[y].emplace_back(x);
  }

  cin >> w;
}

int getBuildDate(int x) {
  if (buildDate[x] != -1) return buildDate[x];

  int prevDate = 0;
  for (auto i: required[x]) {
    prevDate = max(prevDate, getBuildDate(i));
  }
  return buildDate[x] = prevDate + buildTime[x];
}

void solve() {
  input();

  cout << getBuildDate(w) << '\n';
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
