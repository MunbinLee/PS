#include <iostream>

#define MAX_TC 10
#define MAX_NODE 201

using namespace std;

struct Node {
  bool is_op;
  int left, right;
};

int res;
bool needOp;
Node node[MAX_NODE];

void addNode(int key, bool is_op, int left, int right) {
  node[key].is_op = is_op;
  node[key].left = left;
  node[key].right = right;
}

bool isOp(const string &s) {
  if (s == "+" || s == "-" || s == "*" || s == "/") return true;
  return false;
}

void input() {
  int n;
  scanf("%d", &n);

  while (n--) {
    int key;
    scanf("%d", &key);

    string value;
    cin >> value;
    bool is_op = isOp(value);

    int left = 0;
    int right = 0;
    if (getc(stdin) != '\n') {
      scanf("%d", &left);
      if (getc(stdin) != '\n') scanf("%d", &right);
    }

    addNode(key, is_op, left, right);
  }

}

void solve(int key) {
  int left = node[key].left;
  if (left != 0) solve(left);

  if (node[key].is_op != needOp) {
    res = 0;
  }
  needOp ^= true;

  int right = node[key].right;
  if (right != 0) solve(right);
}

int main() {
  for (int tc = 1; tc <= MAX_TC; tc++) {
    res = 1;
    needOp = false;

    input();
    solve(1);
    printf("#%d %d\n", tc, res);
  }
  return 0;
}