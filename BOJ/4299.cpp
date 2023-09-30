#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b;
  cin >> a >> b;
  if ((a + b) % 2) {
    cout << "-1";
    return 0;
  }

  int x = (a + b) / 2;
  int y = a - x;

  if (y < 0) cout << "-1";
  else cout << x << ' ' << y;
  return 0;
}
