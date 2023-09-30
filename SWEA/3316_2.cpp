#include <iostream>
#include <array>
#include <vector>

#define div 1000000007

using namespace std;

int size;
array<int, 16> arr;
vector<array<int, 16>> dp;
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
  arr.fill(-1);

  for (int tc = 1; tc <= t; tc++) {
    cin >> heads;
    size = (int) heads.size();
    dp = vector<array<int, 16>>(size + 1, arr);

    printf("#%d %d\n", tc, solve(0, 1));
  }
  return 0;
}