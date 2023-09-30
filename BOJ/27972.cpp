#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int increasing = 1;
  int decreasing = 1;
  int mx = 1;

  int m, last;
  cin >> m >> last;
  while (--m) {
    int p;
    cin >> p;
    if (p == last) continue;
    if (p > last) {
      decreasing = 1;
      increasing++;
      mx = max(mx, increasing);
    } else {
      increasing = 1;
      decreasing++;
      mx = max(mx, decreasing);
    }
    last = p;
  }

  cout << mx;
  return 0;
}
