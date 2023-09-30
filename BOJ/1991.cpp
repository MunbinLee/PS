#include <iostream>

#define MAX_NODE 26

using namespace std;

struct Node {
  int left, right;
};

Node node[MAX_NODE];

void addNode(int key, int left, int right) {
  node[key].left = left;
  node[key].right = right;
}

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  while (n--) {
    char key, left, right;
    cin >> key >> left >> right;

    key -= 'A';
    if (left == '.') left = -1;
    else left -= 'A';
    if (right == '.') right = -1;
    else right -= 'A';

    addNode(key, left, right);
  }
}

void print(int key) {
  cout << (char) (key + 'A');
}

void solve(int type, int key) {
  if (type == 0) print(key);

  int left = node[key].left;
  if (left != -1) solve(type, left);

  if (type == 1) print(key);

  int right = node[key].right;
  if (right != -1) solve(type, right);

  if (type == 2) print(key);
}

int main() {
  input();

  for (int type = 0; type < 3; type++) {
    solve(type, 0);
    cout << '\n';
  }
  return 0;
}
