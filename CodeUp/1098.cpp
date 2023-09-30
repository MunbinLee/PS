#include <iostream>
#include <vector>

using namespace std;

void bar(vector<vector<int>> &v, int l, int d, int y, int x) {
  if (d) {
    for (int i = y; i < y + l; i++) {
      if (i >= v.size()) break;
      v[i][x] = 1;
    }
  } else {
    for (int i = x; i < x + l; i++) {
      if (i >= v[0].size()) break;
      v[y][i] = 1;
    }
  }
}

int main() {
  int h, w, n, l, d, y, x;
  cin >> h >> w >> n;
  vector<vector<int>> v(h + 1, vector<int>(w + 1, 0));
  while (n--) {
    cin >> l >> d >> y >> x;
    bar(v, l, d, y, x);
  }

  for (int i = 1; i < h + 1; i++) {
    for (int j = 1; j < w + 1; j++) {
      cout << v[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
