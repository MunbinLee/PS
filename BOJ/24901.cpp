#include <iostream>

using namespace std;

void printBinary(int n) {
  if (n / 2 != 0) {
    printBinary(n / 2);
  }
  cout << n % 2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i <= n; i++) {
    printBinary(i);
  }
  return 0;
}