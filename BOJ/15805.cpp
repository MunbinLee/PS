#include <iostream>
#include <unordered_map>

using namespace std;

int k = 1;
unordered_map<int, int> res;

struct Node {
  int key;
  Node *parent;
  unordered_map<int, Node *> child;

  Node(int key, Node *parent) : key(key), parent(parent) {};

  int getParentKey() const {
    if (!parent) return -1;
    return parent->key;
  }

  Node *insert(int x) {
    k++;
    res[x] = key;
    return child[x] = new Node(x, this);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n >> x;
  res[x] = -1;
  Node *root = new Node(x, nullptr);
  Node *cur = root;

  while (--n) {
    cin >> x;
    if (cur->getParentKey() == x) {
      cur = cur->parent;
    } else if (cur->child[x]) {
      cur = cur->child[x];
    } else {
      cur = cur->insert(x);
    }
  }

  cout << k << '\n';
  for (int i = 0; i < k; i++) {
    cout << res[i] << ' ';
  }

  return 0;
}
