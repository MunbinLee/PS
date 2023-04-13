#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct Shark {
  int r, c, s, d, z;

  Shark(int r, int c, int s, int d, int z) : r(r), c(c), s(s), d(d), z(z) {}
};

int dr[5] = {0, -1, 1, 0, 0};
int dc[5] = {0, 0, 0, 1, -1};
int R, C, M;
unordered_set<Shark *> st;
vector<vector<Shark *>> board;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> R >> C >> M;
  board.resize(R + 1, vector<Shark *>(C + 1));
  for (int i = 0; i < M; i++) {
    int r, c, s, d, z;
    cin >> r >> c >> s >> d >> z;
    if (d == 1 || d == 2) s %= R * 2 - 2;
    else s %= C * 2 - 2;
    auto *shark = new Shark(r, c, s, d, z);
    st.emplace(shark);
    board[r][c] = shark;
  }
}

int reverseDir(int dir) {
  if (dir == 1) return 2;
  else if (dir == 2) return 1;
  else if (dir == 3) return 4;
  else return 3;
}

void moveSharks() {
  for (auto shark: st) {
    board[shark->r][shark->c] = nullptr;
  }

  vector<Shark *> dead;
  for (auto shark: st) {
    int &r = shark->r;
    int &c = shark->c;
    int &d = shark->d;

    int s = shark->s;
    while (s) {
      int nr = r + dr[d];
      int nc = c + dc[d];
      if (nr == 0 || nr == R + 1 || nc == 0 || nc == C + 1) {
        d = reverseDir(d);
        continue;
      }
      r = nr;
      c = nc;
      s--;
    }

    auto &other = board[r][c];
    if (!other) {
      other = shark;
    } else if (shark->z > other->z) {
      dead.emplace_back(other);
      other = shark;
    } else {
      dead.emplace_back(shark);
    }
  }

  for (auto shark: dead) {
    st.erase(shark);
  }
}

void solve() {
  int sumSize = 0;
  for (int i = 1; i <= C; i++) {
    for (int j = 1; j <= R; j++) {
      auto &shark = board[j][i];
      if (!shark) continue;
      sumSize += shark->z;
      st.erase(shark);
      board[j][i] = nullptr;
      break;
    }
    moveSharks();
  }
  cout << sumSize;
}

int main() {
  input();
  solve();
  return 0;
}
