#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, f, i;
  cin >> n >> f;
  for (i = 0; i <= 99; i++) {
    if ((n / 100 * 100 + i) % f == 0) break;
  }

  cout.width(2);
  cout.fill('0');
  cout << i;
  return 0;
}
