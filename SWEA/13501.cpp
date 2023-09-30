#include <iostream>
#include <list>

using namespace std;

list<int> ls;

void insert(int pos, int num) {
  auto it = ls.begin();
  advance(it, pos);
  ls.insert(it, num);
}

void del(int pos) {
  auto it = ls.begin();
  advance(it, pos);
  ls.erase(it);
}

void change(int pos, int num) {
  del(pos);
  insert(pos, num);
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int n, m, l;
    scanf("%d %d %d", &n, &m, &l);
    ls.clear();

    for (int i = 0; i < n; i++) {
      int tmp;
      scanf("%d", &tmp);
      ls.emplace_back(tmp);
    }

    for (int i = 0; i < m; i++) {
      string cmd;
      cin >> cmd;
      if (cmd == "I") {
        int pos, num;
        scanf("%d %d", &pos, &num);
        insert(pos, num);
      } else if (cmd == "D") {
        int pos;
        scanf("%d", &pos);
        del(pos);
      } else {
        int pos, num;
        scanf("%d %d", &pos, &num);
        change(pos, num);
      }
    }

    int res = -1;
    if (l < ls.size()) {
      auto it = next(ls.begin(), l);
      res = *it;
    }
    printf("#%d %d\n", tc, res);
  }
  return 0;
}