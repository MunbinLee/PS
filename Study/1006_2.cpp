#include <iostream>
#include <vector>

#define MAX INT32_MAX
#define WALL 1

using namespace std;

int n;
int mn = MAX;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<vector<int>> map;
vector<vector<bool>> visited;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  map = vector<vector<int>>(n, vector<int>(n));
  visited = vector<vector<bool>>(n, vector<bool>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];
    }
  }
}

bool isWall(int y, int x) {
  if (y == -1 || y == n || x == -1 || x == n) return true;
  if (map[y][x] == WALL) return true;
  return false;
}

void dfs(int y, int x, int dir, int cnt) {
  if (y == n - 1 && x == n - 1) {
    if (cnt < mn) mn = cnt;
    return;
  }

  int ny = y + dy[dir];
  int nx = x + dx[dir];
  if (visited[ny][nx]) return;
  if (isWall(ny, nx)) {
    for (int i = 0; i < 4; i++) {
      int nny = y + dy[i];
      int nnx = x + dx[i];
      if (visited[nny][nnx]) continue;
      if (isWall(nny, nnx)) continue;
      visited[nny][nnx] = true;
      dfs(nny, nnx, i, cnt + 1);
      visited[nny][nnx] = false;
    }
    return;
  }

  visited[ny][nx] = true;
  dfs(ny, nx, dir, cnt);
  visited[ny][nx] = false;
}

int main() {
  input();

  visited[0][0] = true;
  for (int i = 1; i <= 2; i++) {
    dfs(0, 0, i, 0);
  }

  cout << mn;
  return 0;
}