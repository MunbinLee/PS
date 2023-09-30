#include <iostream>

using namespace std;

bool chk(int n) {
  for (int i = n; i >= 666; i /= 10) {
    if (i % 1000 == 666) return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int cnt = 0;

  for (int i = 666;; i++) {
    if (chk(i)) cnt++;
    if (n == cnt) {
      cout << i;
      return 0;
    }
  }
}
