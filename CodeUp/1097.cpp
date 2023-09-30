#include <iostream>

using namespace std;

void reverse(int board[20][20], int y, int x) {
  for (int i = 1; i <= 19; i++) {
    board[i][x] ^= 1;
  }
  for (int i = 1; i <= 19; i++) {
    board[y][i] ^= 1;
  }
}

int main() {
  int n, y, x, num;
  int board[20][20]{};

  for (int i = 1; i <= 19; i++) {
    for (int j = 1; j <= 19; j++) {
      cin >> num;
      board[i][j] = num;
    }
  }

  cin >> n;
  while (n--) {
    cin >> y >> x;
    reverse(board, y, x);
  }

  for (int i = 1; i <= 19; i++) {
    for (int j = 1; j <= 19; j++) {
      cout << board[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
