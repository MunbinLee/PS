#include <iostream>
#include <cstring>
#include <list>
#include <unordered_map>

using namespace std;
typedef pair<int, int> ip;

int n, m, tmp, roomIdx;
bool isWall[1000][1000];
int cnt[1000][1000];
int room[1000][1000];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
list<ip> ls;
unordered_map<int, bool> mp;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(cnt, -1, sizeof(cnt));
  cin >> n >> m;
  cin.get();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (cin.get() == '1') {
        isWall[i][j] = true;
        cnt[i][j] = 0;
      }
    }
    cin.get();
  }
}

void isMovable(int r, int c) {
  for (int i = 0; i < 4; i++) {
    int nr = r + dr[i];
    int nc = c + dc[i];
    if (nr == -1 || nr == n || nc == -1 || nc == m) continue;
    if (cnt[nr][nc] != -1) continue;
    tmp++;
    cnt[nr][nc] = 0;
    ls.emplace_back(nr, nc);
    isMovable(nr, nc);
  }
}

int destroyWall(int r, int c) {
  mp.clear();
  int res = 1;
  for (int i = 0; i < 4; i++) {
    int nr = r + dr[i];
    int nc = c + dc[i];
    if (nr == -1 || nr == n || nc == -1 || nc == m) continue;
    if (isWall[nr][nc]) continue;
    int idx = room[nr][nc];
    if (mp.contains(idx)) continue;
    mp[idx] = true;
    res += cnt[nr][nc];
  }
  return res;
}

void solve() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (cnt[i][j] != -1) continue;
      tmp = 1;
      cnt[i][j] = 0;
      ls.emplace_back(i, j);
      isMovable(i, j);
      for (auto [r, c]: ls) {
        cnt[r][c] = tmp;
        room[r][c] = roomIdx;
      }
      roomIdx++;
      ls.clear();
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!isWall[i][j]) {
        cout << '0';
      } else {
        cout << destroyWall(i, j) % 10;
      }
    }
    cout << '\n';
  }
}

int main() {
  input();
  solve();
  return 0;
}
