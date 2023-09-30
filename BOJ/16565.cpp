#include <iostream>
#include <array>
#include <vector>

using namespace std;

const int mod = 10007;

array<vector<int>, 53> memo;

int comb(int a, int b) {
  int &m = memo[a][b];
  if (m != -1) return m;

  return m = comb(a - 1, b - 1) + comb(a - 1, b) % mod;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 1; i < 53; i++) {
    memo[i].assign(i + 1, -1);
    memo[i][0] = 1;
    memo[i][i] = 1;
  }

  int n;
  cin >> n;

  int res;
  if (n <= 3) {
    res = 0;
  } else if (n <= 7) {
    res = 13 * comb(48, n - 4) % mod;
  } else {
    res = comb(52, n) % mod;
  }

  cout << res;

  return 0;
}
