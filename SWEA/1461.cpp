#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

enum {
  EMPTY = 0,
  CORE = 1,
  WIRE = 2
};

int n, maxConnect, minSum;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
vector<vector<int>> map;
vector<pair<int, int>> cores;

void input() {
  scanf("%d", &n);
  map = vector<vector<int>>(n, vector<int>(n));

  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      int tmp;
      scanf("%d", &tmp);
      map[r][c] = tmp;

      if (tmp == CORE && r != 0 && r != n - 1 && c != 0 && c != n - 1) {
        cores.emplace_back(r, c);
      }
    }
  }
}

int installWire(int y, int x, int dir) {
  int cnt = 0;
  while (true) {
    y += dy[dir];
    x += dx[dir];
    if (y == -1 || y == n || x == -1 || x == n) return cnt;
    if (map[y][x] != EMPTY) {
      while (true) {
        y -= dy[dir];
        x -= dx[dir];
        if (map[y][x] == CORE) break;
        map[y][x] = EMPTY;
      }
      return false;
    }
    map[y][x] = WIRE;
    cnt++;
  }
}

void removeWire(int y, int x, int dir) {
  while (true) {
    y += dy[dir];
    x += dx[dir];
    if (y == -1 || y == n || x == -1 || x == n) return;
    map[y][x] = EMPTY;
  }
}

void updateBestRecord(int connect, int sum) {
  if (connect > maxConnect) {
    maxConnect = connect;
    minSum = sum;
  } else if (connect == maxConnect && sum < minSum) minSum = sum;
}

void solve(int i, int connect, int sum) {
  if (i == cores.size()) {
    updateBestRecord(connect, sum);
    return;
  }

  int y, x;
  tie(y, x) = cores[i];

  int wireCnt = false;
  for (int d = 0; d < 4; d++) {
    wireCnt = installWire(y, x, d);
    if (!wireCnt) continue;
    solve(i + 1, connect + 1, sum + wireCnt);
    removeWire(y, x, d);
  }

  if (!wireCnt) {
    updateBestRecord(connect, sum);
    solve(i + 1, connect, sum);
  }
}

int main() {
  int t;
  scanf("%d", &t);

  for (int tc = 1; tc <= t; tc++) {
    minSum = INT32_MAX;
    maxConnect = 0;
    cores.clear();

    input();
    solve(0, 0, 0);
    printf("#%d %d\n", tc, minSum);
  }
  return 0;
}
