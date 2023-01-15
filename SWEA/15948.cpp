#include <iostream>
#include <vector>
#include <array>

using namespace std;

int r, c, res;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
array<bool, 26> visited;
vector<string> map;

void input() {
  scanf("%d %d", &r, &c);
  map = vector<string>(r);
  for (string &i : map) cin >> i;
}

void dfs(int y, int x, int cnt) {
  if (cnt > res) res = cnt;

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny == -1 || ny == r || nx == -1 || nx == c) continue;
    int idx = map[ny][nx] - 'A';
    if (visited[idx]) continue;

    visited[idx] = true;
    dfs(ny, nx, cnt + 1);
    visited[idx] = false;
  }
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    input();

    res = 1;
    visited = array<bool, 26>();
    int idx = map[0][0] - 'A';
    visited[idx] = true;

    solve(0, 0, 1);
    printf("#%d %d\n", i, res);
  }
}