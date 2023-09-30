#include <iostream>

using namespace std;

bool solve(int n, int m) {
  for (int i = n - 1; i >= 0; i--) {
    if (!(m & (1 << i))) return false;
  }
  return true;
}

int main() {
  int t;
  scanf("%d", &t);

  for (int i = 1; i <= t; i++) {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("#%d %s\n", i, solve(n, m) ? "ON" : "OFF");
  }
  return 0;
}
