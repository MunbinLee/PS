#include <iostream>

using namespace std;

struct Node {
  string key, part, value;
  Node *left = nullptr;
  Node *right = nullptr;
};

Node *root;

Node *createNode(string key, string part, string value) {
  Node *node = new Node;
  node->key = std::move(key);
  node->part = std::move(part);
  node->value = std::move(value);
  return node;
}

Node *insertNode(Node *node, const string &key, const string &part, const string &value) {
  if (!root) return root = createNode(key, part, value);
  if (!node) return createNode(key, part, value);

  if (key < node->key) node->left = insertNode(node->left, key, part, value);
  else if (key > node->key) node->right = insertNode(node->right, key, part, value);

  return node;
}

void findNode(const string &key) {
  Node *node = root;
  Node *floor, *ceil;

  while (node) {
    if (node->key == key) {
      cout << node->value << '\n';
      return;
    }

    if (key > node->key) {
      floor = node;
      node = node->right;
    } else {
      ceil = node;
      node = node->left;
    }
  }
  cout << floor->key << ' ' << floor->part << ' ' << ceil->key << ' ' << ceil->part << '\n';
}

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  string key, part, tmp, value;
  cin.get();
  while (n--) {
    part = '(';
    getline(cin, key, '(');
    key.erase(key.size() - 1);
    getline(cin, tmp, ')');
    part += tmp + ')';
    cin.get();
    getline(cin, value);

    insertNode(root, key, part, value);
  }
}

void solve() {
  int k;
  cin >> k;
  string key;
  cin.get();
  while (k--) {
    getline(cin, key);
    findNode(key);
  }
}

int main() {
  input();
  solve();
  return 0;
}
