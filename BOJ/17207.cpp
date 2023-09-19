#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int arr[2][5][5];
  for (auto &i: arr) {
    for (auto &j: i) {
      for (int &k: j) {
        int num;
        cin >> num;
        k = num;
      }
    }
  }

  int mn = INT32_MAX;
  int mxIdx = -1;
  for (int i = 0; i < 5; i++) {
    int cnt = 0;
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {
        cnt += arr[0][i][k] * arr[1][k][j];
      }
    }
    if (cnt < mn || cnt == mn && i > mxIdx) {
      mn = cnt;
      mxIdx = i;
    }
  }

  string nameArr[] = {"Inseo", "Junsuk", "Jungwoo", "Jinwoo", "Youngki"};
  cout << nameArr[mxIdx];
  return 0;
}
