#include <iostream>

using namespace std;

int t, n;

int main() {
  scanf("%d", &t);

  for (int i = 1; i <= t; i++) {
    scanf("%d", &n);
    printf("#%d %d\n", i, n * n);
  }
  return 0;
}
