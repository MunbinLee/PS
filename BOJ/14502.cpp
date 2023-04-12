#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pr;

enum {
  EMPTY = 0,
  WALL = 1,
  VIRUS = 2
};

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int n, m, e;
vector<vector<int>> board;
vector<pr> Empty;
vector<pr> virus;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  board.resize(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int &b = board[i][j];
      cin >> b;
      if (b == EMPTY) Empty.emplace_back(i, j);
      else if (b == VIRUS) virus.emplace_back(i, j);
    }
  }
  e = Empty.size();
}

int getArea(int a, int b, int c) {
  int v = 0;
  vector<vector<int>> tmpBoard = board;
  tmpBoard[Empty[a].first][Empty[a].second] = WALL;
  tmpBoard[Empty[b].first][Empty[b].second] = WALL;
  tmpBoard[Empty[c].first][Empty[c].second] = WALL;

  queue<pr> q;
  for (auto pos: virus) {
    q.emplace(pos);
  }

  while (!q.empty()) {
    auto [y, x] = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny == -1 || ny == n || nx == -1 || nx == m) continue;
      if (tmpBoard[ny][nx] != EMPTY) continue;
      tmpBoard[ny][nx] = VIRUS;
      q.emplace(ny, nx);
      v++;
    }
  }
  return e - v - 3;
}

void solve() {
  int maxArea = 0;
  for (int i = 0; i + 2 < e; i++) {
    for (int j = i + 1; j + 1 < e; j++) {
      for (int k = j + 1; k < e; k++) {
        maxArea = max(maxArea, getArea(i, j, k));
      }
    }
  }
  cout << maxArea;
}

int main() {
  input();
  solve();
  return 0;
}
