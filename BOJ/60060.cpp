#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node {
  unordered_map<char, Node *> child;
};

auto root = new Node();

void insertNode(string &s) {
  auto pNode = root;
  for (char ch: s) {
    if (!pNode->child[ch]) pNode->child[ch] = new Node;
    pNode = pNode->child[ch];
  }
}

int find(int idx, Node *pNode, string &s, string cur) {
  if (!pNode) return 0;
  if (idx == s.size()) {
    if (pNode->child.empty()) return 1;
    else return 0;
  }

  int cnt = 0;
  if (s[idx] == '?') {
    for (auto [k, v]: pNode->child) {
      cnt += find(idx + 1, v, s, cur + k);
    }
  } else {
    Node *nNode = pNode->child[s[idx]];
    if (nNode) cnt += find(idx + 1, nNode, s, cur + s[idx]);
  }
  return cnt;
}

vector<int> solution(vector<string> words, vector<string> queries) {
  for (string &word: words) {
    insertNode(word);
  }

  vector<int> answer;
  answer.reserve(queries.size());
  for (string &query: queries) {
    answer.emplace_back(find(0, root, query, {}));
  }
  return answer;
}

int main() {
  vector<string> words = {"frodo", "front", "frost", "frozen", "frame", "kakao"};
  vector<string> queries = {"fro??", "????o", "fr???", "fro???", "pro?"};
  vector<int> v = solution(words, queries);
  for (int i: v) {
    cout << i << ' ';
  }
  return 0;
}