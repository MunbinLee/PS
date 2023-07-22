#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
using tp = tuple<int, int, int>;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int n, m, sy, sx;
vector<vector<int>> board, dist;
queue<tp> q;

void input() {
  cin >> n >> m;
  board.resize(n, vector<int>(m));
  dist.resize(n, vector<int>(m, -1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int &b = board[i][j];
      cin >> b;
      if (b == 2) {
        sy = i;
        sx = j;
      }
    }
  }
}

void bfs() {
  q.emplace(sy, sx, 0);
  dist[sy][sx] = 0;
  while (!q.empty()) {
    auto [y, x, cost] = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny == -1 || ny == n || nx == -1 || nx == m) continue;
      if (!board[ny][nx]) continue;
      if (dist[ny][nx] != -1) continue;
      dist[ny][nx] = cost + 1;
      q.emplace(ny, nx, cost + 1);
    }
  }
}

void output() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (dist[i][j] == -1 && !board[i][j]) cout << '0';
      else cout << dist[i][j];
      cout << ' ';
    }
    cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  input();
  bfs();
  output();
  return 0;
}