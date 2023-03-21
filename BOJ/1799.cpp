#include <iostream>
#include <vector>

using namespace std;

int n, q, mx;
int dy[4] = {-1, -1, 1, 1};
int dx[4] = {-1, 1, -1, 1};
vector<vector<bool>> board;
vector<pair<int, int>> ls;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  board.resize(n, vector<bool>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int tmp;
      cin >> tmp;
      board[i][j] = tmp;
      if (board[i][j]) {
        ls.emplace_back(i, j);
        q++;
      }
    }
  }
}

void solve(int i, int cnt, vector<vector<bool>> b) {
  if (cnt > mx) mx = cnt;
  if (i == q) return;

  solve(i + 1, cnt, b);
  auto [y, x] = ls[i];
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
  solve(i + 1, cnt + 1, b);
}

int main() {
  input();
  solve(0, 0, board);
  cout << mx;
  return 0;
}
