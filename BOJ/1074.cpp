#include <iostream>

using namespace std;

int n, r, c;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> r >> c;
}

void solve(int y, int x, int size, int cnt) {
  if (size == 0) {
    cout << cnt;
    return;
  }

  size--;
  int d = 1 << size;
  if (r >= y + d) {
    y += d;
    cnt += d * d * 2;
  }
  if (c >= x + d) {
    x += d;
    cnt += d * d;
  }
  solve(y, x, size, cnt);
}

int main() {
  input();
  solve(0, 0, n, 0);
  return 0;
}
