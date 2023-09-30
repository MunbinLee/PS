#include <iostream>
#include <cstring>

#define div 1000000007

using namespace std;

int size;
int **dp;
string heads;

int solve(int day, int previous) {
  if (dp[day][previous] != -1) return dp[day][previous];

  int head = 1 << (heads[day] - 'A');
  int res = 0;

  for (int i = 1; i < 16; i++) {
    if (!(i & previous && i & head)) continue;
    if (day == size - 1) res++;
    else res = (res + solve(day + 1, i)) % div;
  }

  dp[day][previous] = res;
  return res;
}

int main() {
  int t;
  cin >> t;

  for (int tc = 1; tc <= t; tc++) {
    cin >> heads;
    size = (int) heads.size();
    dp = new int *[size + 1];
    for (int i = 0; i <= size; i++) {
      dp[i] = new int[16];
      memset(dp[i], -1, 64);
    }

    printf("#%d %d\n", tc, solve(0, 1));
  }
  return 0;
}