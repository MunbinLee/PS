#include <vector>
#include <iostream>

using namespace std;

int n;
vector<int> lefts;
vector<int> rights;
vector<vector<int>> dp;

int DP(int l, int r) {
  if (l == n || r == n) return 0;
  if (dp[l][r] == -1) {
    dp[l][r] = 0;
    if (lefts[l] > rights[r]) dp[l][r] += rights[r] + DP(l, r + 1);
    else dp[l][r] += max(DP(l + 1, r), DP(l + 1, r + 1));
  }
  return dp[l][r];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  lefts = vector<int>(n);
  rights = vector<int>(n);
  dp = vector(n, vector<int>(n, -1));
  for (int i = 0; i < n; i++) cin >> lefts[i];
  for (int i = 0; i < n; i++) cin >> rights[i];
  cout << DP(0, 0);
  return 0;
}
