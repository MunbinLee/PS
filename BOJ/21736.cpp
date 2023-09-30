#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pr = pair<int, int>;

enum {
  WALL = 'X',
  DOYEON = 'I',
  PERSON = 'P'
};

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int n, m, cnt;
pr doyeon;
vector<vector<char>> board;
queue<pr> q;

void input() {
  cin >> n >> m;
  board.resize(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char &b = board[i][j];
      cin >> b;
      if (b == 'I') doyeon = {i, j};
    }
  }
}

void bfs() {
  q.emplace(doyeon);
  board[doyeon.first][doyeon.second] = WALL;

  while (!q.empty()) {
    auto [cy, cx] = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = cy + dy[i];
      int nx = cx + dx[i];
      if (ny == -1 || ny == n || nx == -1 || nx == m) continue;
      char &b = board[ny][nx];
      if (b == WALL) continue;
      if (b == PERSON) cnt++;
      b = WALL;
      q.emplace(ny, nx);
    }
  }

  if (cnt) cout << cnt;
  else cout << "TT";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  input();
  bfs();
  return 0;
}