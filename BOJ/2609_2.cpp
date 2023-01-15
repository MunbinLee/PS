#include <iostream>

using namespace std;

int gcd(int x, int y) {
  if (x == 0) return y;
  return gcd(y % x, x);
}

int lcm(int x, int y) {
  return x * y / gcd(x, y);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int x, y;
  cin >> x >> y;

  cout << gcd(x, y) << '\n' << lcm(x, y);
}
