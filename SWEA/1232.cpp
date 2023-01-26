#include <iostream>

#define MAX_TC 10
#define MAX_NODE 1001

using namespace std;

struct Node {
  double num;
  char op;
  int left, right;
};

Node node[MAX_NODE];

void addNode(int key, int num, char op, int left, int right) {
  node[key].num = num;
  node[key].op = op;
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
    int num = 0;
    char op = 0;
    if (isOp(value)) op = value[0];
    else num = stoi(value);

    int left = 0;
    int right = 0;
    if (getc(stdin) != '\n') {
      scanf("%d", &left);
      if (getc(stdin) != '\n') scanf("%d", &right);
    }

    addNode(key, num, op, left, right);
  }
}

void solve(int key) {
  int left = node[key].left;
  int right = node[key].right;

  if (left != 0) solve(left);
  if (right != 0) solve(right);

  if (node[key].left && node[key].right) {
    double lv = node[node[key].left].num;
    double rv = node[node[key].right].num;
    switch (node[key].op) {
      case '+': node[key].num = lv + rv;
        break;
      case '-': node[key].num = lv - rv;
        break;
      case '*': node[key].num = lv * rv;
        break;
      case '/': node[key].num = (double) lv / rv;
        break;
      default: printf("ERROR\n");
        break;
    }
  }
}

int main() {
  for (int tc = 1; tc <= MAX_TC; tc++) {
    input();
    solve(1);
    printf("#%d %.f\n", tc, node[1].num);
  }
  return 0;
}
