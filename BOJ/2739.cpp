#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 1; i <= 9; i++) {
    printf("%d * %d = %d\n", n, i, n * i);
  }
  return 0;
}
