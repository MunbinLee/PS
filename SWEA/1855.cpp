#include <iostream>

using namespace std;

int n;

void input() {
  scanf("%d", &n);
}

void solve() {

}

int main() {
  int t;
  scanf("%d", &t);

  for (int tc = 1; tc <= t; tc++) {
    input();
    solve();
    printf("#%d %d\n", tc, -1);
  }
  return 0;
}
