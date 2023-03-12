#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;
string x, y;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> x >> y;
}

int lcs(int m, int n) {
  if (m == 0 || n == 0) return 0;
  if (x[m - 1] == y[n - 1]) return dp[m][n] = lcs(m - 1, n - 1) + 1;
  if (dp[m][n] != -1) return dp[m][n];
  return dp[m][n] = max(lcs(m, n - 1), lcs(m - 1, n));
}

void solve() {
  int m = (int) x.size();
  int n = (int) y.size();
  dp.assign(m + 1, vector<int>(n + 1, -1));

  cout << lcs(m, n) << '\n';
  // print lcs
  string res;
  while (m && n) {
    if (x[m - 1] == y[n - 1]) {
      res += x[m - 1];
      m--;
      n--;
    } else if (dp[m - 1][n] > dp[m][n - 1]) {
      m--;
    } else {
      n--;
    }
  }
  reverse(res.begin(), res.end());
  cout << res;
}

int main() {
  input();
  solve();
  return 0;
}
