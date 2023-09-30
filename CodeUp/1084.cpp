#include <iostream>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      for (int k = 0; k < c; k++) {
        printf("%d %d %d\n", i, j, k);
      }
    }
  }
  cout << a * b * c;
  return 0;
}
