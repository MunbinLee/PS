#include <iostream>

using namespace std;

int main() {
  int a, m, d, n;
  cin >> a >> m >> d >> n;
  long long res = a;
  for (int i = 2; i <= n; i++) {
    res *= m;
    res += d;
  }
  cout << res;
  return 0;
}
