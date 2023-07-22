#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
using tp = tuple<int, int, int, bool>;

const int INF = 987654321;
const char WALL = '1';
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int n, m;
vector<string> board;
vector<vector<int>> minDist;

void input() {
  cin >> n >> m;
  board.resize(n);
  minDist.resize(n, vector<int>(m, INF));
  for (auto &v: board) {
    cin >> v;
  }
}

void solve() {
  if (n == 1 && m == 1) {
    cout << '1';
    return;
  }

  minDist[0][0] = 1;
  queue<tp> q;
  q.emplace(0, 0, 1, true);
  while (!q.empty()) {
    auto [cy, cx, dist, power] = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = cy + dy[i];
      int nx = cx + dx[i];
      if (ny == -1 || ny == n || nx == -1 || nx == m) continue;
      int ndist = dist + 1;
      if (ndist >= minDist[ny][nx]) continue;
      if (board[ny][nx] == WALL && !power) continue;
      if (board[ny][nx] == WALL) {
        minDist[ny][nx] = ndist;
        q.emplace(ny, nx, ndist, false);
        continue;
      }
      minDist[ny][nx] = ndist;
      q.emplace(ny, nx, ndist, power);
    }
  }

  int &d = minDist[n - 1][m - 1];
  if (d == INF) d = -1;
  cout << d;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  input();
  solve();
}