#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pr = pair<int, int>;

enum {
  VISITED = '1'
};

pr dPos[4] = {
    {-1, 0},
    {0,  -1},
    {0,  1},
    {1,  0}
};

bool isFirstHole(int y, int x, int n, int m, vector<string> &board) {
  if (board[y][x] == VISITED) return false;

  board[y][x] = VISITED;
  queue<pr> q;
  q.emplace(y, x);

  while (!q.empty()) {
    auto [cy, cx] = q.front();
    q.pop();

    for (auto [dy, dx]: dPos) {
      int ny = cy + dy;
      int nx = cx + dx;
      if (ny == -1 || ny == n || nx == -1 || nx == m) continue;
      if (board[ny][nx] == VISITED) continue;
      board[ny][nx] = VISITED;
      q.emplace(ny, nx);
    }
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<string> board(n);
  for (string &s: board) {
    cin >> s;
  }

  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (isFirstHole(i, j, n, m, board)) res++;
    }
  }

  cout << res;

  return 0;
}
