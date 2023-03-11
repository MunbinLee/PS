#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int map[100][100];
int minTime[100][100];
queue<tuple<int, int, int>> q; // y, x, time

void input() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%1d", &map[i][j]);
      minTime[i][j] = INT32_MAX;
    }
  }
}

int solve() {
  int y, x, time, ny, nx, nTime;
  q.emplace(0, 0, 0);
  while (!q.empty()) {
    tie(y, x, time) = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      ny = y + dy[i];
      nx = x + dx[i];
      if (ny == -1 || ny == n || nx == -1 || nx == n) continue;
      nTime = time + map[ny][nx];
      if (nTime >= minTime[ny][nx]) continue;
      minTime[ny][nx] = nTime;
      q.emplace(ny, nx, nTime);
    }
  }
  return minTime[n - 1][n - 1];
}

int main() {
  int t;
  scanf("%d", &t);

  for (int tc = 1; tc <= t; tc++) {
    input();
    printf("#%d %d\n", tc, solve());
  }
  return 0;
}
