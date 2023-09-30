#include <iostream>
#include <vector>

using namespace std;

const int dy[] = {-1, 0, 0, 1};
const int dx[] = {0, -1, 1, 0};
int h, w;
char curLabel = 'a';
vector<vector<int>> board;
vector<vector<char>> labels;

int getFlow(int y, int x) {
  int minAlt = board[y][x];
  int res = -1;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny == -1 || ny == h || nx == -1 | nx == w) continue;
    int alt = board[ny][nx];
    if (alt < minAlt) {
      minAlt = alt;
      res = i;
    }
  }
  return res;
}

char setLabel(int y, int x) {
  if (labels[y][x]) return labels[y][x];

  int flow = getFlow(y, x);
  if (flow == -1) return labels[y][x] = curLabel++;

  int ny = y + dy[flow];
  int nx = x + dx[flow];
  return labels[y][x] = setLabel(ny, nx);
}

void solve() {
  curLabel = 'a';

  cin >> h >> w;
  board.assign(h, vector<int>(w));
  labels.assign(h, vector<char>(w));

  for (auto &v: board) {
    for (int &i: v) {
      cin >> i;
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      setLabel(i, j);
    }
  }

  for (auto &v: labels) {
    for (char ch: v) {
      cout << ch << ' ';
    }
    cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ":\n";
    solve();
  }
  return 0;
}
