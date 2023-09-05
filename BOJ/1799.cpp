#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pr = pair<int, int>; // y, x

int dy[4] = {-1, -1, 1, 1};
int dx[4] = {-1, 1, -1, 1};

int n;
int mx[2];
vector<vector<bool>> board;
vector<pr> ls[2];

void solve(int color, int i, int cnt, vector<vector<bool>> b) {
  mx[color] = max(mx[color], cnt);
  if (i == ls[color].size()) return;

  solve(color, i + 1, cnt, b);
  auto [y, x] = ls[color][i];
  if (!b[y][x]) return;
  b[y][x] = false;
  for (int j = 0; j < 4; j++) {
    int ny = y + dy[j];
    int nx = x + dx[j];
    while (true) {
      if (ny == -1 || ny == n || nx == -1 || nx == n) break;
      b[ny][nx] = false;
      ny += dy[j];
      nx += dx[j];
    }
  }
  solve(color, i + 1, cnt + 1, b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  board.resize(n, vector<bool>(n));
  for (auto &v: ls) {
    v.reserve(n * n / 2 + 1);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      bool b;
      cin >> b;
      board[i][j] = b;
      if (!b) continue;
      int color = (i + j) % 2;
      ls[color].emplace_back(i, j);
    }
  }

  int cnt = 0;
  for (int color: {0, 1}) {
    solve(color, 0, 0, board);
    cnt += mx[color];
  }

  cout << cnt;

  return 0;
}
