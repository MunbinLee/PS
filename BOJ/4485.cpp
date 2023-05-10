#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int INF = 987654321;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; n != 0; i++) {
    vector<vector<int>> board(n, vector<int>(n));
    for (auto &v: board) {
      for (int &num: v) {
        cin >> num;
      }
    }
    vector<vector<int>> minCost(n, vector<int>(n, INF));
    queue<tuple<int, int, int>> q;
    int y = 0;
    int x = 0;
    int cost = board[y][x];
    minCost[y][x] = cost;
    q.emplace(y, x, cost);

    while (!q.empty()) {
      auto [cy, cx, ccost] = q.front();
      q.pop();
      for (int j = 0; j < 4; j++) {
        int ny = cy + dy[j];
        int nx = cx + dx[j];
        if (ny == -1 || ny == n || nx == -1 || nx == n) continue;
        int ncost = ccost + board[ny][nx];
        if (ncost >= minCost[ny][nx]) continue;
        minCost[ny][nx] = ncost;
        q.emplace(ny, nx, ncost);
      }
    }
    cout << "Problem " << i << ": " << minCost[n - 1][n - 1] << '\n';
    cin >> n;
  }
  return 0;
}
