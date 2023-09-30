#include <iostream>
#include <stack>

using namespace std;

bool isBalanced(const string &s) {
  stack<char> st;
  for (char c: s) {
    switch (c) {
      case '(':
      case '[':
        st.emplace(c);
        break;
      case ')':
        if (!st.empty() && st.top() == '(') st.pop();
        else return false;
        break;
      case ']':
        if (!st.empty() && st.top() == '[') st.pop();
        else return false;
        break;
      default:
        break;
    }
  }
  return st.empty();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  getline(cin, s);
  while (s != ".") {
    cout << ((isBalanced(s)) ? "yes" : "no") << '\n';
    getline(cin, s);
  }
  return 0;
}
