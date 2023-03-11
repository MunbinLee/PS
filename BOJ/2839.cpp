#include <iostream>

using namespace std;

int getMinCount(int n) {
  for (int five = n / 5; five >= 0; five--) {
    int remainder = n - five * 5;
    if (remainder % 3 == 0) return five + remainder / 3;
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  cout << getMinCount(n);
}
