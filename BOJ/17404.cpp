#include <iostream>
#include <vector>
#include <array>

using namespace std;

const int INF = 987654321;
int n;
vector<array<int, 3>> cost;
vector<array<array<int, 3>, 3>> memo; // 인덱스, 0번 집의 색, 색

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  cost.resize(n);
  memo.resize(n);
  for (auto &i: cost) {
    for (auto &j: i) {
      cin >> j;
    }
  }
}

void solve() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      memo[0][i][j] = INF;
    }
    memo[0][i][i] = cost[0][i];
  }

  for (int i = 1; i < n; i++) { // 인덱스
    for (int j = 0; j < 3; j++) { // 0번 집의 색
      for (int k = 0; k < 3; k++) { // 색
        int &m = memo[i][j][k];
        m = INF;
        for (int l = 0; l < 3; l++) { // 전 집의 색
          if (k == l) continue;
          if (i == n - 1 && k == j) continue;
          m = min(m, memo[i - 1][j][l] + cost[i][k]);
        }
      }
    }
  }

  int mn = INF;
  for (auto i: memo[n - 1]) {
    for (auto j: i) {
      mn = min(mn, j);
    }
  }
  cout << mn;
}

int main() {
  input();
  solve();
  return 0;
}
