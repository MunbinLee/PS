#include <iostream>

#define MAX_NODE 10001

using namespace std;

struct Node {
  int parent;
  int childs[2];
};

int v, e, n1, n2, cnt;
Node node[MAX_NODE];

void input() {
  scanf("%d %d %d %d", &v, &e, &n1, &n2);

  for (int i = 1; i <= v; i++) {
    node[i].parent = 0;
    for (int &child : node[i].childs) {
      child = 0;
    }
  }

  while (e--) {
    int p, c;
    scanf("%d %d", &p, &c);
    if (!node[p].childs[0]) node[p].childs[0] = c;
    else node[p].childs[1] = c;
    node[c].parent = p;
  }
}

int getParent() {
  for (int p1 = n1;; p1 = node[p1].parent) {
    for (int p2 = n2; p2 != 0; p2 = node[p2].parent) {
      if (p1 == p2) return p1;
    }
  }
}

void getCnt(int key) {
  for (int child : node[key].childs) {
    if (child != 0) getCnt(child);
  }
  cnt++;
}

int main() {
  int t;
  scanf("%d", &t);

  for (int tc = 1; tc <= t; tc++) {
    cnt = 0;
    input();
    int parent = getParent();
    getCnt(parent);
    printf("#%d %d %d\n", tc, parent, cnt);
  }
  return 0;
}
