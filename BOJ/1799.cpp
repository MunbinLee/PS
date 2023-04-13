#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> board;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  board.resize(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }
}

void solve() {

}

int main() {
  input();
  solve();
  return 0;
}
