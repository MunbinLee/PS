#include <iostream>
#include <vector>

using namespace std;

int n, k;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
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
  cin >> k;
}

void dfs(int y, int x, int hurt) {
  for (int i = 0; i < 4; i++) {
    if (y == n - 1 && x == n - 1) {
      cout << "Yes";
      exit(0);
    }

    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny == -1 || ny == n || nx == -1 || nx == n) continue;
    if (visited[ny][nx]) continue;
    if (map[ny][nx] == 1) continue;
    int nhurt = hurt + (map[ny][nx] == 2);
    if (nhurt > k) continue;

    visited[ny][nx] = true;
    dfs(ny, nx, nhurt);
    visited[ny][nx] = false;
  }
}

int main() {
  input();

  visited[0][0] = true;
  int hurt = (map[0][0] == 2);

  dfs(0, 0, hurt);
  cout << "No";
  return 0;
}