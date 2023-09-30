#include <iostream>
#include <vector>
#include <queue>

#define CABBAGE 1

using namespace std;

int m, n, k;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<vector<int>> map;
vector<vector<int>> isProtected;
vector<pair<int, int>> cabbage;
queue<pair<int, int>> q;

void input() {
  cin >> m >> n >> k;
  map = vector<vector<int>>(m, vector<int>(n));
  isProtected = vector<vector<int>>(m, vector<int>(n));
  cabbage.resize(k);
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    map[x][y] = CABBAGE;
    cabbage[i] = {x, y};
  }
}

void protect(int x, int y) {
  isProtected[x][y] = true;
  q.emplace(x, y);
  while (!q.empty()) {
    auto [cx, cy] = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = cx + dx[i];
      int ny = cy + dy[i];
      if (nx == -1 || nx == m || ny == -1 || ny == n) continue;
      if (isProtected[nx][ny] || map[nx][ny] != CABBAGE) continue;
      isProtected[nx][ny] = true;
      q.emplace(nx, ny);
    }
  }
}

int solve() {
  int cnt = 0;
  for (auto [x, y]: cabbage) {
    if (!isProtected[x][y]) {
      protect(x, y);
      cnt++;
    }
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    input();
    cout << solve() << '\n';
  }
  return 0;
}
