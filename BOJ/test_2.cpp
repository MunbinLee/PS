#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum {
  EMPTY = 0,
  WALL = 1,
  VISITED = 2
};

int n;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
vector<vector<int>> board;
pair<int, int> startPos, endPos;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  board.resize(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }
  cin >> startPos.first >> startPos.second >> endPos.first >> endPos.second;
  auto [y, x] = startPos;
  board[y][x] = VISITED;
}

bool isReachable(pair<int, int> pos, queue<pair<int, int>> q) {
  if (pos == endPos) return true;

  for (int i = 0; i < 4; i++) {
    int ny = pos.first + dy[i];
    int nx = pos.second + dx[i];
    bool flag = false;

    while (true) {
      if (ny == -1 || ny == n || nx == -1 || nx == n) break;
      if (board[ny][nx] == 1 && flag) break;

      if (board[ny][nx] == EMPTY) {
        board[ny][nx] = VISITED;
        q.emplace(ny, nx);
        if (isReachable({ny, nx}, q)) return true;
        board[ny][nx] = EMPTY;
      } else if (board[ny][nx] == WALL && !flag) {
        flag = true;
      }
      ny += dy[i];
      nx += dx[i];
    }
  }
  return false;
}

int main() {
  input();
  cout << (isReachable(startPos, queue<pair<int, int>>()) ? "Yes" : "No");
  return 0;
}
