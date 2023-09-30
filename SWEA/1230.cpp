#include <iostream>
#include <list>

using namespace std;

list<int> ls;

void insert(int pos, int cnt) {
  auto it = ls.begin();
  advance(it, pos);
  for (int i = 0; i < cnt; i++) {
    int tmp;
    scanf("%d", &tmp);
    ls.insert(it, tmp);
  }
}

void del(int pos, int cnt) {
  auto it_first = ls.begin();
  advance(it_first, pos);
  auto it_last = it_first;
  advance(it_last, cnt);
  ls.erase(it_first, it_last);
}

void append(int cnt) {
  for (int i = 0; i < cnt; i++) {
    int tmp;
    scanf("%d", &tmp);
    ls.emplace_back(tmp);
  }
}

int main() {
  for (int tc = 1; tc <= 10; tc++) {
    int n;
    scanf("%d", &n);
    ls.clear();
    append(n);

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
      string cmd;
      cin >> cmd;
      if (cmd == "I") {
        int pos, cnt;
        scanf("%d %d", &pos, &cnt);
        insert(pos, cnt);
      } else if (cmd == "D") {
        int pos, cnt;
        scanf("%d %d", &pos, &cnt);
        del(pos, cnt);
      } else {
        int cnt;
        scanf("%d", &cnt);
        append(cnt);
      }
    }

    printf("#%d ", tc);
    auto it_first = ls.begin();
    auto it_end = it_first;
    advance(it_end, 10);
    for (auto it = it_first; it != it_end; it++) printf("%d ", *it);
    printf("\n");
  }
  return 0;
}