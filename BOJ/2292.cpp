#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int res = 1;
  int mx = 1;
  for (int i = 1;; i++) {
    if (n <= mx) break;
    res++;
    mx += i * 6;
  }

  cout << res;
  return 0;
}
