#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  for (int tc = 1; tc <= t; tc++) {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> board(n, vector<int>(m));
    for (auto &v: board) {
      for (auto &i: v) {
        cin >> i;
      }
    }

    vector<int> maxRow;
    maxRow.reserve(n);
    for (auto &v: board) {
      int mx = -1;
      for (auto &i: v) {
        mx = max(mx, i);
      }
      maxRow.emplace_back(mx);
    }

    vector<int> maxColumn;
    maxColumn.reserve(m);
    for (int i = 0; i < m; i++) {
      int mx = -1;
      for (int j = 0; j < n; j++) {
        mx = max(mx, board[j][i]);
      }
      maxColumn.emplace_back(mx);
    }

    int safe = 0;
    map<int, bool> safes;
    {
      map<int, bool> visited;
      for (int i: maxRow) {
        visited[i] = true;
      }
      for (int i: maxColumn) {
        if (visited[i]) {
          safes[i] = true;
          safe++;
        }
      }
    }

    int sum = 0;
    while (q--) {
      int r, c, x;
      cin >> r >> c >> x;
      r--;
      c--;

      int &mr = maxRow[r];
      int &mc = maxColumn[c];

      if (x > mr && x > mc) {
        if (safes[mr]) {
          safes[mr] = false;
          safe--;
        } else if (safes[mc]) {
          safes[mc] = false;
          safe--;
        }
        safes[x] = true;
        safe++;
      } else if (x > mr) {
        if (safes[mr]) {
          safes[mr] = false;
          safe--;
        }
        safes[x] = true;
        safe++;
      } else if (x > mc) {
        if (safes[mc]) {
          safes[mc] = false;
          safe--;
        }
        safes[x] = true;
        safe++;
      }
      mr = max(mr, x);
      mc = max(mc, x);
      sum += safe;
    }
    cout << '#' << tc << ' ' << sum << '\n';
  }
  return 0;
}