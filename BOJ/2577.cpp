#include <iostream>

using namespace std;

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n = 1;

  REP(i, 3) {
    int tmp;
    cin >> tmp;
    n *= tmp;
  }

  int arr[10]{};

  while (n) {
    arr[n % 10]++;
    n /= 10;
  }

  for (int i: arr) {
    cout << i << '\n';
  }
  return 0;
}
