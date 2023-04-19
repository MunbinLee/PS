#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string p;

struct Tree {
  struct Node {
    string value;
    Node *left{}, *right{};

    vector<int> memo;

    int dp(int pIdx) {
      if (memo.empty()) memo.assign(p.length() + 1, -1);
      if (memo[pIdx] != -1) return memo[pIdx];

      if (value.empty()) {
        return memo[pIdx] = right->dp(left->dp(pIdx)); // dfs
      } else { // 리프 노드
        for (char i: value) {
          if (p[pIdx] == i) pIdx++;
        }
        return pIdx;
      }
    }
  };

  int nodeCnt = 0;
  Node nodes[501];
  unordered_map<string, Node *> mp;

  Node *getOrCreateNode(const string &s) {
    if (mp.contains(s)) return mp[s];
    return mp[s] = &nodes[nodeCnt++];
  }

  void setChildNode(const string &parent, const string &child1, const string &child2) {
    Node *parentNode = getOrCreateNode(parent);
    Node *childNode1 = getOrCreateNode(child1);
    Node *childNode2 = getOrCreateNode(child2);
    parentNode->left = childNode1;
    parentNode->right = childNode2;
  }

  void setValue(const string &key, const string &value) {
    Node *pNode = getOrCreateNode(key);
    pNode->value = value;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while (n--) {
    Tree *pTree = new Tree();
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
      string s1, s2, dummy;
      cin >> s1 >> dummy >> s2;
      if (isupper(s2[0])) {
        string s3;
        cin >> dummy >> s3;
        pTree->setChildNode(s1, s2, s3);
      } else {
        pTree->setValue(s1, s2);
      }
    }
    string t;
    cin >> t >> p;

    auto t_pNode = pTree->getOrCreateNode(t);
    string res = t_pNode->dp(0) == p.length() ? "YES" : "NO";
    cout << res << '\n';
  }
  return 0;
}
