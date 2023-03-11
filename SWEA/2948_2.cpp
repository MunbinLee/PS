#include <iostream>

#define NHASH 61

using namespace std;

struct Node {
  string s;
  Node *next{};
};

int n, m, cnt;
string tmp;
Node *hTable[NHASH];

int getHash(const string &s) {
  int hash = 5381;
  for (char c: s) {
    hash = ((hash << 5) + hash) + c;
    hash %= NHASH;
  }
  return hash;
}

Node *createNode(const string &s) {
  Node *pNode = new Node;
  pNode->s = s;
  return pNode;
}

void saveNode(const string &s) {
  int hash = getHash(s);
  Node *pNode = hTable[hash];
  if (!pNode) {
    hTable[hash] = createNode(s);
    return;
  }
  while (pNode->next) {
    pNode = pNode->next;
  }
  pNode->next = createNode(s);
}

bool findNode(const string &s) {
  int hash = getHash(s);
  Node *pNode = hTable[hash];
  while (pNode) {
    if (pNode->s == s) return true;
    pNode = pNode->next;
  }
  return false;
}

void init() {
  for (auto &i: hTable) {
    i = nullptr;
  }
}

void solve() {
  init();

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    saveNode(tmp);
  }

  cnt = 0;
  for (int i = 0; i < m; i++) {
    cin >> tmp;
    if (findNode(tmp)) cnt++;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  for (int tc = 1; tc <= t; tc++) {
    solve();
    cout << '#' << tc << ' ' << cnt << '\n';
  }
  return 0;
}
