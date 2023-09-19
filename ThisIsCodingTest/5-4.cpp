#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
using pr = pair<int, int>;
using tp = tuple<int, int, int>;

pr dPos[] = {
    {-1, 0},
    {0,  -1},
    {0,  1},
    {1,  0}
};

int getMinDist(int n, int m, vector<string> &board) {
  queue<tp> q;
  q.emplace(0, 0, 1);

  while (!q.empty()) {
    auto [y, x, dist] = q.front();
    q.pop();
    if (y == n - 1 && x == m - 1) {
      return dist;
    }

    int nDist = dist + 1;
    for (auto [dy, dx]: dPos) {
      int ny = y + dy;
      int nx = x + dx;
      if (ny == -1 || ny == n || nx == -1 || nx == m) continue;
      if (board[ny][nx] == '0') continue;
      q.emplace(ny, nx, nDist);
    }
  }
  return -1;
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

  cout << getMinDist(n, m, board);

  return 0;
}
