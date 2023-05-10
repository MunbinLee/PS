#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> tp;

const int INF = 987654321;
const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

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

    vector<vector<int>> dist(n, vector<int>(n, INF));
    dist[0][0] = board[0][0];
    priority_queue<tp, vector<tp>, less<>> pq;
    pq.emplace(dist[0][0], 0, 0);

    while (!pq.empty()) {
      auto [cost, y, x] = pq.top();
      pq.pop();

      for (int j = 0; j < 4; j++) {
        int ny = y + dy[j];
        int nx = x + dx[j];
        if (ny == -1 || ny == n || nx == -1 || nx == n) continue;
        int ncost = cost + board[ny][nx];
        if (ncost >= dist[ny][nx]) continue;
        dist[ny][nx] = ncost;
        pq.emplace(ncost, ny, nx);
      }
    }

    cout << "Problem " << i << ": " << dist[n - 1][n - 1] << '\n';
    cin >> n;
  }
  return 0;
}
