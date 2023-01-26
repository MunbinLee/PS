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
  if (isWall(y, x)) return;
  if (visited[y][x]) return;
  if (y == n - 1 && x == n - 1) {
    if (cnt < mn) mn = cnt;
    return;
  }

  visited[y][x] = true;
  int ny = y + dy[dir];
  int nx = x + dx[dir];

  if (isWall(ny, nx)) {
    for (int i = 0; i < 4; i++) {
      int nny = y + dy[i];
      int nnx = x + dx[i];
      dfs(nny, nnx, i, dir + 1);
    }
    visited[y][x] = false;
    return;
  }


  dfs(ny, nx, dir, cnt);
  visited[y][x] = false;
}

int main() {
  input();

  for (int i = 1; i <= 2; i++) {
    dfs(0, 0, i, 0);
  }

  if (mn == MAX) cout << "No Path";
  else cout << mn;
  return 0;
}