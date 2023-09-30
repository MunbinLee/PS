#include <iostream>
#include <vector>
#include <list>

using namespace std;

int n, mx;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
vector<vector<int>> board;
list<int> ls;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  board.resize(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
      if (board[i][j] <= mx) continue;
      mx = board[i][j];
    }
  }
}

bool isValidPos(int r, int c) {
  return !(r == -1 || r == n || c == -1 || c == n);
}

void moveBoard(vector<vector<int>> &b, int dir) {
  for (int i = 0; i < n; i++) {
    int r = (dr[dir] == -1) ? n - 1 : (dr[dir] == 1) ? 0 : i;
    int c = (dc[dir] == -1) ? n - 1 : (dc[dir] == 1) ? 0 : i;
    while (isValidPos(r, c)) {
      if (b[r][c]) {
        if (!ls.empty() && b[r][c] == ls.back()) {
          ls.back() *= 2;
          if (ls.back() > mx) mx = ls.back();
          ls.emplace_back(0);
        } else {
          ls.emplace_back(b[r][c]);
        }
      }
      r += dr[dir];
      c += dc[dir];
    }

    ls.remove(0);

    r = (dr[dir] == -1) ? n - 1 : (dr[dir] == 1) ? 0 : i;
    c = (dc[dir] == -1) ? n - 1 : (dc[dir] == 1) ? 0 : i;
    while (isValidPos(r, c)) {
      if (!ls.empty()) {
        b[r][c] = ls.front();
        ls.pop_front();
      } else {
        b[r][c] = 0;
      }
      r += dr[dir];
      c += dc[dir];
    }
  }
}

void dfs(vector<vector<int>> b, int dir, int cnt) {
  if (cnt == 5) return;
  moveBoard(b, dir);
  for (int i = 0; i < 4; i++) {
    dfs(b, i, cnt + 1);
  }
}

void solve() {
  for (int i = 0; i < 4; i++) {
    dfs(board, i, 0);
  }
}

int main() {
  input();
  solve();
  cout << mx;
  return 0;
}
