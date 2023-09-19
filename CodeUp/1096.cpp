#include <iostream>

using namespace std;

int main() {
  int n, y, x;
  int board[19][19]{};

  cin >> n;
  while (n--) {
    cin >> y >> x;
    board[y - 1][x - 1] = 1;
  }

  for (int i = 0; i < 19; i++) {
    for (int j = 0; j < 19; j++) {
      cout << board[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
