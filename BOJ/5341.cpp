#include <iostream>

using namespace std;

int dp[101] = {-1, 1};

int DP(int n) {
  if (!dp[n]) {
    dp[n] = DP(n - 1) + n;
  }
  return dp[n];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  while (true) {
    int n;
    cin >> n;
    if (!n) break;
    cout << DP(n) << '\n';
  }
  return 0;
}
