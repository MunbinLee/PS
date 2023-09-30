#include <iostream>
#include <vector>

using namespace std;

vector<int> buildTime;
vector<int> buildDate;
vector<vector<int>> required;

void setBuildDate(int b) {
  int maxTime = 0;
  for (int i: required[b]) {
    if (buildDate[i] == -1) setBuildDate(i);
    if (buildDate[i] > maxTime) maxTime = buildDate[i];
  }
  buildDate[b] = maxTime + buildTime[b];
}

void solve() {
  int n, k;
  cin >> n >> k;
  buildTime.resize(n + 1);
  buildDate = vector<int>(n + 1, -1);
  for (int i = 1; i <= n; i++) {
    cin >> buildTime[i];
  }

  required = vector(n + 1, vector<int>());
  while (k--) {
    int x, y;
    cin >> x >> y;
    required[y].emplace_back(x);
  }

  int w;
  cin >> w;
  setBuildDate(w);
  cout << buildDate[w] << '\n';
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
