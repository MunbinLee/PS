#include <iostream>

using namespace std;

int gcd(int x, int y) {
  for (int i = min(x, y);; i--) {
    if (x % i == 0 && y % i == 0) return i;
  }
}

int lcm(int x, int y) {
  for (int i = max(x, y);; i++) {
    if (i % x == 0 && i % y == 0) return i;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int x, y;
  cin >> x >> y;

  cout << gcd(x, y) << '\n' << lcm(x, y);
}
