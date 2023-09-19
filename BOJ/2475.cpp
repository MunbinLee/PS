#include <iostream>

using namespace std;

int main() {
  int res = 0;

  for (int i = 0; i < 5; i++) {
    int n;
    cin >> n;
    res += n * n;
  }

  cout << res % 10;
  return 0;
}
