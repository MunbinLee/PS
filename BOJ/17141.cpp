#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pr;
enum {
  BLANK = 0,
  WALL = 1,
  VIRUS = 2
};

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int n, m, numZone, numBlank;
vector<vector<int>> board;
vector<vector<bool>> visited;
vector<pr> zoneVirus;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  board.resize(n, vector<int>(n));
  visited.resize(n, vector<bool>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int &b = board[i][j];
      cin >> b;
      if (b == WALL) {
        visited[i][j] = true;
      } else if (b == VIRUS) {
        zoneVirus.emplace_back(i, j);
        b = BLANK;
        numZone++;
        numBlank++;
      } else {
        numBlank++;
      }
    }
  }
}

int getTime(const vector<int> &zone) {
  vector<vector<int>> tmpBoard = board;
  vector<vector<bool>> tmpVisited = visited;
  queue<pr> q;
  for (int i: zone) {
    q.emplace(zoneVirus[i]);
    auto [y, x] = zoneVirus[i];
    tmpVisited[y][x] = true;
  }

  int maxTime = 0;
  int v = 0;
  while (!q.empty()) {
    auto [y, x] = q.front();
    q.pop();
    v++;
    int time = tmpBoard[y][x];
    maxTime = max(maxTime, time);
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny == -1 || ny == n || nx == -1 || nx == n || tmpVisited[ny][nx]) continue;
      tmpVisited[ny][nx] = true;
      tmpBoard[ny][nx] = time + 1;
      q.emplace(ny, nx);
    }
  }
  if (v == numBlank) return maxTime;
  return INT32_MAX;
}

int getMinTime(int zoneIdx, vector<int> zone) {
  if (zoneIdx == numZone) {
    if (zone.size() == m)
      return getTime(zone);
    else return INT32_MAX;
  }

  int no = getMinTime(zoneIdx + 1, zone);
  if (zone.size() == m) return no;

  zone.emplace_back(zoneIdx);
  int yes = getMinTime(zoneIdx + 1, zone);
  return min(yes, no);
}

void solve() {
  int minTime = getMinTime(0, {});
  if (minTime != INT32_MAX) cout << minTime;
  else cout << "-1";
}

int main() {
  input();
  solve();
  return 0;
}
