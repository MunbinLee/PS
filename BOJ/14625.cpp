#include <iostream>

using namespace std;

bool contains(int x, int n) {
  if (n == 0 && x < 10) return true;
  
  while (x) {
    if (x % 10 == n) return true;
    x /= 10;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int h[2];
  int m[2];
  int n;
  cin >> h[0] >> m[0] >> h[1] >> m[1] >> n;

  int cnt = 0;
  while (true) {

    if (contains(h[0], n) || contains(m[0], n)) cnt++;
    if (h[0] == h[1] && m[0] == m[1]) break;
    m[0]++;
    if (m[0] == 60) {
      h[0]++;
      m[0] = 0;
    }
  }

  cout << cnt;

  return 0;
}
