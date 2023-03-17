#include <iostream>
#include <cmath>

using namespace std;

int n, r, c, cnt;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> r >> c;
}

void ZSearch(int y, int x, int size) {
  if (size == 0) {
    if (y == r && x == c) {
      cout << cnt;
      exit(0);
    }
    cnt++;

    return;
  };
  int d = (int) pow(2, size - 1);
  ZSearch(y, x, size - 1);
  ZSearch(y, x + d, size - 1);
  ZSearch(y + d, x, size - 1);
  ZSearch(y + d, x + d, size - 1);
}

void solve() {
  ZSearch(0, 0, n);
}

int main() {
  input();
  solve();
  return 0;
}
