#include <iostream>
#include <map>
#include <functional>

#define MAX_CHILD 10

using namespace std;

struct Node {
  bool isTerminal = false;
  Node *child[MAX_CHILD]{};
};

bool isEmpty(Node *pNode) {
  if (!pNode) return true;
  for (auto &i: pNode->child) {
    if (i) return false;
  }
  return true;
}

Node *root;

Node *createNode() {
  Node *pNode = new Node;
  return pNode;
}

void init() {
  root = createNode();
}

void insertNode(const string &s) {
  Node *pNode = root;
  for (char c: s) {
    int i = c - '0';
    if (!pNode->child[i]) pNode->child[i] = createNode();
    pNode = pNode->child[i];
  }
  pNode->isTerminal = true;
}

bool check() {
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    insertNode(s);
  }

  bool flag = true;
  function<void(Node *)> sol = [&](Node *pNode) {
    if (!isEmpty(pNode)) {
      if (pNode->isTerminal) flag = false;
      for (auto &i: pNode->child) {
        sol(i);
      }
    }
  };
  sol(root);
  return flag;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    init();
    cout << (check() ? "YES" : "NO") << '\n';
  }
  return 0;
}
