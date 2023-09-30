#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t, s;
  cin >> t >> s;

  bool isLunch = t >= 12 && t <= 16;

  int res = isLunch && !s ? 320 : 280;
  cout << res;

  return 0;
}