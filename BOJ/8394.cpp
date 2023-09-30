#include <vector>
#include <iostream>

#define vi vector<int>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vi dp = vi(n + 1);
  dp[0] = 1;
  dp[1] = 1;

  for (int i = 2; i <= n; i++) {
    dp[i] = (dp[i - 1] + dp[i - 2]) % 10;
  }

  cout << dp[n];
  return 0;
}
