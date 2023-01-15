#include <iostream>

using namespace std;

int t;
char x, y;
string n;

void solve() {
  int size = (int) n.size();
  int last_y = -1;

  if (size == 1) {
    if (n[0] >= y) n = y;
    else if (n[0] >= x && x != '0') n = x;
    else n = "-1";
    return;
  }

  for (int i = 0; i < size; i++) {
    if (n[i] == x) continue;

    if (n[i] == y) {
      last_y = i;
      continue;
    }

    if (n[i] > y) {
      for (int j = i; j < size; j++) {
        n[j] = y;
      }
      return;
    }

    if (n[i] > x) {
      if (i == 0 && x == '0') {
        n = string(size - 1, y);
        return;
      }
      n[i] = x;
      for (int j = i + 1; j < size; j++) {
        n[j] = y;
      }
      return;
    }

    if (last_y == -1) {
      n = string(size - 1, y);
      return;
    }

    n[last_y] = x;
    for (int j = last_y + 1; j < size; j++) {
      n[j] = y;
    }
  }
}

int main() {
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    cin >> n >> x >> y;
    solve();
    printf("#%d ", i);
    cout << n << '\n';
  }
  return 0;
}