#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef vector<vector<int>> v2;
typedef pair<int, int> pr;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int bfs(v2 &board, const int n, const int m, int r, int c) {
  if (board[r][c] == 0) return 0;

  queue<pr> q;
  q.emplace(r, c);
  int cnt = board[r][c];
  board[r][c] = 0;
  while (!q.empty()) {
    auto [cr, cc] = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nr = cr + dr[i];
      int nc = cc + dc[i];
      if (nr == -1 || nr == n || nc == -1 || nc == m || board[nr][nc] == 0) continue;
      cnt += board[nr][nc];
      board[nr][nc] = 0;
      q.emplace(nr, nc);
    }
  }
  return cnt;
}

int getVolume(v2 &board, const int n, const int m) {
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int z = bfs(board, n, m, i, j);
      res = max(res, z);
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    v2 board = vector(n, vector<int>(m));
    for (auto &v: board) {
      for (auto &i: v) {
        cin >> i;
      }
    }
    int volume = getVolume(board, n, m);
    cout << volume << '\n';
  }
  return 0;
}