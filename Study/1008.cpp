#include <iostream>
#include <queue>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  priority_queue<int> pq;
  int tmp;
  while (n--) {
    scanf("%d", &tmp);
    if (tmp == 0) {
      if (pq.empty()) printf("-1\n");
      else {
        printf("%d\n", pq.top());
        pq.pop();
      }
    } else {
      pq.emplace(tmp);
    }
  }
  return 0;
}
