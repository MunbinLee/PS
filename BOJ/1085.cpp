#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int x, y, w, h;
  cin >> x >> y >> w >> h;

  cout << min(min(x, y), min(w - x, h - y));
  return 0;
}
