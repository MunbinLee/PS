#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v, dp;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  v = vector<int>(n);
  dp = vector<int>(n);
  for (int &i: v) cin >> i;
}

int solve() {
  int res = 1;
  for (int i = 0; i < n; i++) {
    dp[i] = 1;
    for (int j = i - 1; j >= 0; j--) {
      if (v[i] <= v[j]) continue;
      if (dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1;
    }
    if (dp[i] > res) res = dp[i];
  }
  return res;
}

int main() {
  input();
  cout << solve();
  return 0;
}
