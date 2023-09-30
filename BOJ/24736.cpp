#include <iostream>

using namespace std;

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))

int a, b, c, d, e;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  REP(i, 2) {
    cin >> a >> b >> c >> d >> e;
    cout << a * 6 + b * 3 + c * 2 + d + e * 2 << ' ';
  }
  return 0;
}
