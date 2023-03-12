#include <iostream>

using namespace std;

int r, c, maxCnt;
char map[20][21];
bool visited[26];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    cin >> map[i];
  }
}

void dfs(int y, int x, int cnt) {
  if (cnt > maxCnt) maxCnt = cnt;
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
  input();
  int y = 0;
  int x = 0;
  int idx = map[y][x] - 'A';
  visited[idx] = true;
  dfs(y, x, 1);
  cout << maxCnt;
  return 0;
}
