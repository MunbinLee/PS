#include <iostream>
#include <array>
#include <vector>

#define div 1000000007

using namespace std;

array<long long int, 16> arr;
vector<array<long long int, 16>> dp;
string heads;

int solve() {
  long long int cnt = 0;
  int size = (int) heads.size();
  dp = vector<array<long long int, 16>>(size, arr);

  for (int day = 0; day < size; day++) {
    int head = 1 << (heads[day] - 'A');
    for (int i = 1; i < 16; i++) {
      if (day == 0) {
        if ((i & (head | 1)) != (head | 1)) continue;
        dp[day][i] = 1;
        continue;
      }
      if (!dp[day - 1][i]) continue;
      for (int j = 1; j < 16; j++) {
        if (!((i & j) && (j & head))) continue;
        dp[day][j] += dp[day - 1][i];
        dp[day][j] %= div;
      }
    }
  }

  for (int i = 1; i < 16; i++) {
    cnt += dp[size - 1][i];
    cnt %= div;
  }
  return (int) cnt;
}

int main() {
  int t;
  scanf("%d", &t);

  for (int tc = 1; tc <= t; tc++) {
    cin >> heads;
    printf("#%d %d\n", tc, solve());
  }
  return 0;
}
