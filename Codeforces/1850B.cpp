#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    int maxB = -1;
    int res = -1;
    for (int i = 1; i <= n; i++) {
      int a, b;
      cin >> a >> b;
      if (a > 10) continue;
      if (b > maxB) {
        maxB = b;
        res = i;
      }
    }
    cout << res << '\n';
  }

  return 0;
}