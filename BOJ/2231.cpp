#include <iostream>

using namespace std;

int decompose(int n) {
  int ret = n;
  for (int i = n; i; i /= 10) ret += i % 10;
  return ret;
}

int solve(int n) {
  for (int i = 1; i < n; i++) {
    if (decompose(i) == n) return i;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  cout << solve(n);
  return 0;
}
