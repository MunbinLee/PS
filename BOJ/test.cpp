#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node {
  unordered_map<char, Node *> children;

  Node *getOrCreateChild(char ch) {
    if (children[ch]) return children[ch];
    children[ch] = new Node;
    return children[ch];
  }
};

Node *root = new Node;

vector<string> solution(vector<string> merchantNames) {
  vector<string> answer;
  for (auto &name: merchantNames) {
    Node *pNode = root;
    for (char ch: name) {
      pNode = pNode->getOrCreateChild(ch);
    }
  }
  return answer;
}

int main() {
  vector<string> names;
  names.emplace_back("abcd");
  solution(names);
  return 0;
}