#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int BFS(int l, int r1, int c1, int r2, int c2) {
  if (r1 == r2 && c1 == c2) return 0;
  vector<vector<bool>> visited(l + 1, vector<bool>(l + 1));
  vector<vector<bool>> dist(l + 1, vector<bool>(l + 1));
  visited[r1][c1] = true;
  queue<pair<int, int>> q;
  q.push({r1, c1});

  while (!q.empty()) {
    int r = q.front().first;
    int c = q.front().second;
    q.pop();

    for (int i = 0; i < 8; i++) {
      int nr = r + dr[i];
      int nc = c + dc[i];
      if (nr <= 0 || nr > l || nc <= 0 || nc > l) continue;
      if (visited[nr][nc]) continue;
      visited[nr][nc] = true;
      dist[nr][nc] = dist[r][c] + 1;
      if (nr == r2 && nc == c2) {
        //cout << dist[nr][nc] << '\n';
        //return;
      }
      q.push({nr, nc});
    }
  }
  return dist[r2][c2];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  while (n--) {
    int l, r1, c1, r2, c2;
    cin >> l >> r1 >> c1 >> r2 >> c2;
    cout << BFS(l, r1, c1, r2, c2) << '\n';
  }
  return 0;
}
