#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pr;

int h, w;

int prToInt(pr p);

pr intToPr(int n);

struct UnionFind {
  vector<int> parent;

  UnionFind() {
    int maxKey = prToInt({h, w});
    parent.assign(maxKey, 0);
    for (int i = 0; i < maxKey; i++) {
      parent[i] = i;
    }
  }

  int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
  }

  int find(pr p) {
    return find(prToInt(p));
  }

  void merge(int a, int b) {
    a = find(a);
    b = find(b);
    parent[b] = a;
  }
};

const int dy[] = {-1, 0, 0, 1};
const int dx[] = {0, -1, 1, 0};
char curLabel = 'a';
vector<vector<int>> board;
vector<vector<char>> labels;
UnionFind *unionFind;

int prToInt(pr p) {
  return p.first * w + p.second;
}

pr intToPr(int n) {
  int y = n / w;
  int x = n % w;
  return {y, x};
}

int getFlow(int y, int x) {
  int minAlt = board[y][x];
  int res = -1;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny == -1 || ny == h || nx == -1 || nx == w) continue;
    int alt = board[ny][nx];
    if (alt < minAlt) {
      minAlt = alt;
      res = i;
    }
  }
  return res;
}

void setUnion(int y, int x, int parent) {
  int key = prToInt({y, x});
  unionFind->merge(key, parent);

  int flow = getFlow(y, x);
  if (flow == -1) return;

  int ny = y + dy[flow];
  int nx = x + dx[flow];
  setUnion(ny, nx, key);
}

void solve() {
  curLabel = 'a';

  cin >> h >> w;
  unionFind = new UnionFind();
  board.assign(h, vector<int>(w));
  labels.assign(h, vector<char>(w));

  for (auto &v: board) {
    for (int &i: v) {
      cin >> i;
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      setUnion(i, j, prToInt({i, j}));
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int key = unionFind->find({i, j});
      auto [y, x] = intToPr(key);
      if (!labels[y][x]) labels[y][x] = curLabel++;
      labels[i][j] = labels[y][x];
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
