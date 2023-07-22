#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  int cnt = 0;
  while (n != 1) {
    int target = max(n / k * k, 1);
    cnt += n - target;
    n = target;

    if (n == 1) break;

    while (n % k == 0) {
      cnt++;
      n /= k;
    }
  }

  cout << cnt;

  return 0;
}