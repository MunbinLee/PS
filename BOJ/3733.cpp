#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b;

  while (cin >> a >> b) {
    cout << b / (a + 1) << '\n';
  }
  return 0;
}
