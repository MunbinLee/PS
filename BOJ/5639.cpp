#include <iostream>

#define MAX_NODE 10000

using namespace std;

struct Node {
  int key;
  Node *left, *right;
};

int nodeIdx;
Node *root;
Node node[MAX_NODE];

Node *addNode(int key) {
  node[nodeIdx].key = key;
  node[nodeIdx].left = nullptr;
  node[nodeIdx].right = nullptr;

  return &node[nodeIdx++];
}

Node *insertNode(Node *pnode, int key) {
  if (!pnode) return addNode(key);

  if (key < pnode->key) pnode->left = insertNode(pnode->left, key);
  else pnode->right = insertNode(pnode->right, key);

  return pnode;
}

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  root = insertNode(nullptr, n);

  while (cin >> n) {
    insertNode(root, n);
  }
}

void solve(Node *pnode) {
  if (pnode->left) solve(pnode->left);
  if (pnode->right) solve(pnode->right);
  cout << pnode->key << '\n';
}

int main() {
  input();
  solve(root);
  return 0;
}
