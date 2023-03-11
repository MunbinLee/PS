#include <iostream>

using namespace std;

int dp[15][15];

int getResidents(int floor, int room) {
  if (dp[floor][room]) return dp[floor][room];
  for (int i = 1; i <= room; i++) {
    dp[floor][room] += getResidents(floor - 1, i);
  }
  return dp[floor][room];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 1; i <= 14; i++) {
    dp[0][i] = i;
  }

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int k, n;
    cin >> k >> n;
    cout << getResidents(k, n) << '\n';
  }
  return 0;
}
