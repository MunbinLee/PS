#include <iostream>

using namespace std;

int n, m;
int a[3000];
int b[100];

void input() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &b[i]);
  }
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
