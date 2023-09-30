#include <iostream>
#include <vector>

using namespace std;
using pr = pair<int, int>;

int getTurnLeftDir(int dir) {
  dir--;
  if (dir == -1) dir = 3;
  return dir;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // 북, 동, 남, 서
  pr dPos[4] = {
      {-1, 0},
      {0,  1},
      {1,  0},
      {0,  -1},
  };

  int n, m, y, x, dir;
  cin >> n >> m >> y >> x >> dir;

  vector<vector<int>> visited(n, vector<int>(m));
  for (auto &v: visited) {
    for (int &i: v) {
      cin >> i;
    }
  }

  int res = 0;
  int oldDir = -1;
  while (true) {
    dir = getTurnLeftDir(dir);

    if (oldDir == -1) {
      oldDir = dir;
    } else if (dir == oldDir) {
      auto [dy, dx] = dPos[dir];
      int ny = y - dy;
      int nx = x - dx;
      if (ny == -1 || ny == n || nx == -1 || nx == m) break;
      y = ny;
      x = nx;
      continue;
    }

    auto [dy, dx] = dPos[dir];
    int ny = y + dy;
    int nx = x + dx;
    if (ny == -1 || ny == n || nx == -1 || nx == m) continue;
    if (visited[ny][nx]) continue;

    visited[ny][nx] = true;
    oldDir = -1;
    res++;
  }

  cout << res;

  return 0;
}
