#include <iostream>

#define MAX_TC 10
#define MAX_NODE 101

using namespace std;

struct Node {
  char value;
  int left, right;
};

string res;
Node node[MAX_NODE];

void addNode(int key, char value, int left, int right) {
  node[key].value = value;
  node[key].left = left;
  node[key].right = right;
}

void input() {
  res = "";

  int n;
  scanf("%d", &n);

  while (n--) {
    int key;
    int left = 0;
    int right = 0;
    char value;

    scanf("%d", &key);
    scanf(" %c", &value);
    if (getc(stdin) != '\n') {
      scanf("%d", &left);
      if (getc(stdin) != '\n') scanf("%d", &right);
    }

    addNode(key, value, left, right);
  }
}

void solve(int key) {
  int left = node[key].left;
  if (left != 0) solve(left);

  res += node[key].value;

  int right = node[key].right;
  if (right != 0) solve(right);
}

int main() {
  for (int tc = 1; tc <= MAX_TC; tc++) {
    input();
    solve(1);
    printf("#%d %s\n", tc, res.c_str());
  }
  return 0;
}
