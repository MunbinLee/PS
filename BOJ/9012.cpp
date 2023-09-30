#include <iostream>
#include <stack>

using namespace std;

bool isBalanced(const string &s) {
  stack<char> st;
  for (char c: s) {
    if (c == '(') st.emplace('(');
    else if (c == ')') {
      if (st.empty()) return false;
      st.pop();
    }
  }
  return st.empty();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    cout << ((isBalanced(s)) ? "YES" : "NO") << '\n';
  }
  return 0;
}
