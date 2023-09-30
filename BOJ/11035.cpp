#include <iostream>
#include <vector>

using namespace std;

int solve(int n, int k) {
  vector<bool> removed(n + 1);

  for (int i = 2; i <= n; i++) {
    if (removed[i]) continue;
    for (int j = 1; i * j <= n; j++) {
      if (removed[i * j]) continue;
      removed[i * j] = true;
      k--;
      if (!k) return i * j;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  while (cin >> n >> k) {
    cout << solve(n, k) << '\n';
  }
  return 0;
}
