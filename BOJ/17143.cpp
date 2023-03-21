#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct Shark {
  int r, c, s, d, z;
  bool updated = false;

  explicit Shark(int r, int c, int s, int d, int z) : r(r), c(c), s(s), d(d), z(z) {}
};

int dr[5] = {0, -1, 1, 0, 0};
int dc[5] = {0, 0, 0, 1, -1};

int R, C, res;
list<Shark *> ls;
vector<vector<Shark *>> board, emptyBoard;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int M;
  cin >> R >> C >> M;
  board.resize(R + 1, vector<Shark *>(C + 1));
  emptyBoard.resize(R + 1, vector<Shark *>(C + 1));
  while (M--) {
    int r, c, s, d, z;
    cin >> r >> c >> s >> d >> z;
    auto *pShark = new Shark(r, c, s, d, z);
    ls.emplace_back(pShark);
    board[r][c] = pShark;
  }
}

void catchShark(int r, int c) {
  Shark *pShark = board[r][c];
  res += pShark->z;
  ls.remove(pShark);
  board[r][c] = nullptr;
}

void reverseDir(int &dir) {
  if (dir == 1) dir = 2;
  else if (dir == 2) dir = 1;
  else if (dir == 3) dir = 4;
  else if (dir == 4) dir = 3;
}

void moveShark() {
  board = emptyBoard;
  for (auto pShark: ls) {
    pShark->updated = false;
  }

  while (!ls.empty()) {
    Shark *pShark = ls.front();
    if (pShark->updated) break;
    ls.pop_front();

    int &r = pShark->r;
    int &c = pShark->c;
    int &d = pShark->d;
    int s = pShark->s;
    int z = pShark->z;

    board[r][c] = nullptr;
    int nr = r + dr[d];
    int nc = pShark->c + dc[d];
    while (s) {
      if (nr == 0 || nr == R + 1 || nc == 0 || nc == C + 1) {
        reverseDir(d);
        nr = r + dr[d];
        nc = c + dc[d];
        continue;
      }
      r = nr;
      c = nc;
      nr += dr[d];
      nc += dc[d];
      s--;
    }

    pShark->updated = true;
    if (board[r][c]) { // 두 상어가 겹칠 경우
      if (z > board[r][c]->z) { // 잡아먹음
        ls.remove(board[r][c]);
        board[r][c] = pShark;
        ls.emplace_back(pShark);
      }
      // else 잡아먹힘
    } else {
      board[r][c] = pShark;
      ls.emplace_back(pShark);
    }
  }
}

void solve() {
  for (int i = 1; i <= C; i++) { // 낚시왕의 위치
    for (int j = 1; j <= R; j++) {
      if (board[j][i]) {
        catchShark(j, i);
        break;
      }
    }
    moveShark();
  }
  cout << res;
}

int main() {
  input();
  solve();
  return 0;
}
