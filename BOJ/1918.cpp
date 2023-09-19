#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  unordered_map<char, int> mp;
  mp.insert({'+', 1});
  mp.insert({'-', 1});
  mp.insert({'*', 2});
  mp.insert({'/', 2});
  mp.insert({'(', -1});
  mp.insert({')', -1});
  stack<char> st;
  string s;
  cin >> s;

  for (char c: s) {
    if (c >= 'A' and c <= 'Z') cout << c;

    else if (c == '+' || c == '-' || c == '*' || c == '/') {
      while (!st.empty() && mp[st.top()] >= mp[c]) {
        cout << st.top();
        st.pop();
      }
      st.push(c);

    } else if (c == '(') {
      st.push(c);

    } else if (c == ')') {
      while (st.top() != '(') {
        cout << st.top();
        st.pop();
      }
      st.pop();
    }
  }

  while (!st.empty()) {
    cout << st.top();
    st.pop();
  }
  return 0;
}
