#include <iostream>

#define INF 987654321

using namespace std;

int dp[5001];

int getMinCount(int n) {
  if (n < 0) return INF;
  if (dp[n]) return dp[n];
  return dp[n] = min(getMinCount(n - 3) + 1, getMinCount(n - 5) + 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  dp[3] = 1;
  dp[5] = 1;

  int n;
  cin >> n;
  int res = getMinCount(n);
  if (res > INF) res = -1;
  cout << res;
  return 0;
}
