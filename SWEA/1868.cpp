#include <iostream>

#define MINE '*'

using namespace std;

int n, cnt;
int mineCnt[300][300];
char map[300][300];

void input() {
  scanf("%d", &n);
  cnt = n * n;
  for (int i = 0; i < n; i++) {
    scanf("%s", map[i]);
    for (int j = 0; j < n; j++) {
      mineCnt[i][j] = 0;
    }
  }
}

void markMine(int r, int c) {
  for (int dr = -1; dr <= 1; dr++) {
    for (int dc = -1; dc <= 1; dc++) {
      if (dr == 0 && dc == 0) continue;
      int nr = r + dr;
      int nc = c + dc;
      if (nr == -1 || nr == n || nc == -1 || nc == n) continue;
      if (map[nr][nc] == MINE) continue;
      mineCnt[nr][nc]++;
    }
  }
}

void checkMine() {
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      if (map[r][c] == MINE) markMine(r, c);
    }
  }
}

void click(int r, int c) {
  if (map[r][c] == MINE) return;
  if (mineCnt[r][c] == -1) return;

  cnt--;
  if (mineCnt[r][c] != 0) {
    mineCnt[r][c] = -1;
    return;
  }
  mineCnt[r][c] = -1;

  for (int dr = -1; dr <= 1; dr++) {
    for (int dc = -1; dc <= 1; dc++) {
      int nr = r + dr;
      int nc = c + dc;
      if (nr == -1 || nr == n || nc == -1 || nc == n) continue;
      click(nr, nc);
    }
  }
}

void solve() {
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      if (map[r][c] == MINE) {
        cnt--;
        continue;
      }
      if (mineCnt[r][c] == 0) {
        click(r, c);
        cnt++;
      }
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);

  for (int tc = 1; tc <= t; tc++) {
    input();
    checkMine();
    solve();
    printf("#%d %d\n", tc, cnt);
  }
  return 0;
}