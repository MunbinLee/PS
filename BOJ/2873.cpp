#include <iostream>
#include <vector>

#define REP(i, n) for (int(i) = 0; (i) < (n); ++(i))

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int r, c;
  cin >> r >> c;
  vector<vector<int>> v(r, vector<int>(c));

  REP(i, r) {
    REP(j, c) {
      int value;
      cin >> value;
      v[i][j] = value;
    }
  }

  char dir[] = {'R', 'L', 'D', 'U'};
  if (r % 2) {
    REP(i, r) {
      char ch = dir[i % 2];
      REP(j, c - 1) {
        cout << ch;
      }
      if (i != r - 1) cout << 'D';
    }
  } else if (c % 2) {
    REP(i, c) {
      char ch = dir[i % 2 + 2];
      REP(j, r - 1) {
        cout << ch;
      }
      if (i != c - 1) cout << 'R';
    }
  } else {
    int mn = INT32_MAX;
    int mr, mc;
    REP(i, r) {
      REP(j, c) {
        int value = v[i][j];
        if ((i + j) % 2 and value < mn) {
          mn = value;
          mr = i;
          mc = j;
        }
      }
    }

    int metMn = 0;
    for (int i = 0; i < r; i += 2) {
      if (i / 2 != mr / 2) {
        char ch = dir[metMn];
        REP(j, c - 1) {
          cout << ch;
        }
        cout << 'D';
        ch = dir[(metMn + 1) % 2];
        REP(j, c - 1) {
          cout << ch;
        }
        if (i != r - 2) cout << 'D';
      } else {
        metMn = 1;
        int y = i;
        int x = 0;
        while (true) {
          if (mr == y + 1 and mc == x) {
            cout << "RD";
            y++;
            x++;
            break;
          }
          cout << "DR";
          y++;
          x++;
          if (y == i + 1 and mr == i and mc == x) {
            break;
          }
          cout << "UR";
          y--;
          x++;
          if (mr == y + 1 and mc == x) {
            cout << "RD";
            y++;
            x++;
            break;
          }
        }
        while (true) {
          if (y == i + 1 and x == c - 1) break;
          cout << "RURD";
          x += 2;
        }
        if (i != r - 2) cout << 'D';
      }
    }
  }
  return 0;
}
