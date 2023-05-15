#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int d1, d2, x;
  cin >> d1 >> d2 >> x;

  if (d2 > d1) swap(d1, d2);
  double v1 = 1.0 * x / d1;
  double v2 = 1.0 * (100 - x) / d2;
  double v3 = v1 + v2;
  double d3 = 100 / v3;

  cout.precision(6);
  cout << fixed << d3;
  return 0;
}
