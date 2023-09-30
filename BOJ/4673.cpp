#include <iostream>
#include <vector>

using namespace std;

int d(int n) {
  int res = n;

  while (n) {
    res += n % 10;
    n /= 10;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<bool> notSelfNum(10001);
  for (int i = 1; i <= 10000; i++) {
    int n = d(i);
    if (n > 10000) continue;
    notSelfNum[n] = true;
  }

  for (int i = 1; i <= 10000; i++) {
    if (!notSelfNum[i]) cout << i << '\n';
  }
  return 0;
}
