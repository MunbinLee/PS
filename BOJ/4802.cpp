#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
using singleFunction = pair<vector<char>, char>;
using function = vector<singleFunction>;

struct Tree {
  struct Node {
    unordered_map<char, Node *> childs;
    vector<int> memo;

    Node() {
      memo.resize(26);
    }
  };

  Node *root;
};

unordered_map<char, function> functions;

void input() {
  char name;
  cin >> name;
  while (name != '#') {
    int numParams;
    cin >> numParams;
    vector<char> params(numParams);
    for (char &param: params) {
      cin >> param;
    }
    char retType;
    cin >> retType;
    functions[name].emplace_back(params, retType);

    cin >> name;
  }
}

void solve() {
  char retType;
  cin >> retType;
  while (retType != '#') {
    auto tree = new Tree;
    auto pNode = tree;
    int numParams;
    cin >> numParams;
    

    cin >> retType;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  input();
  solve();

  return 0;
}
