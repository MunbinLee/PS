#include <iostream>
#include <array>

using namespace std;

array<bool, 10> visited;

bool check(int num) {
  while (num) {
    visited[num % 10] = true;
    num /= 10;
  }

  bool allVisited = true;
  for (bool b: visited) {
    if (!b) allVisited = false;
  }
  return allVisited;
}

int main() {
  int t;
  scanf("%d", &t);

  for (int i = 1; i <= t; i++) {
    int n;
    scanf("%d", &n);
    visited = array<bool, 10>();

    int cnt = 1;
    while (true) {
      if (check(n * cnt)) break;
      cnt++;
    }

    printf("#%d %d\n", i, n * cnt);
  }
  return 0;
}
