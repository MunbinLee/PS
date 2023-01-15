#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int n;
int mn_cnt = INT32_MAX;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
vector<vector<bool>> visited;
vector<vector<int>> map;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  visited = vector<vector<bool>>(n, vector<bool>(n));
  map = vector<vector<int>>(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];
    }
  }
}

void dfs(int y, int x, int dir, int cnt) {
  for (int i = (dir == -1) ? 0 : dir; i != -1 && i == dir || i < 4; i++) {
    if (y == n - 1 && x == n - 1) return;

    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny == -1 || ny == n || nx == -1 || nx == n) continue;
    if (visited[ny][nx]) continue;
    if (map[ny][nx] == 1) continue;
    if (cnt < mn_cnt) continue;

    visited[ny][nx] = true;
    dfs(ny, nx, i, cnt + 1);
    visited[ny][nx] = false;
  }
}

int main() {
  input();
  dfs(0, 0, -1, 0);
  cout << mn_cnt;
  return 0;
}
