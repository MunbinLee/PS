#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;
string s;
vector<int> missing;

string combine(const string &str) {
  string res = s;
  for (int i = 0; i < missing.size(); i++) {
    int idx = missing[i];
    res[idx] = str[i];
  }
  return res;
}

bool isValid(const string &str) {
  stack<char> st;
  for (char ch: str) {
    if (ch == '(') {
      st.emplace(ch);
    } else if (ch == ')' && st.top() == '(') {
      st.pop();
    } else {
      return false;
    }
  }
  return st.empty();
}

void solve(int idx, string guess) {
  if (idx == missing.size()) {
    string res = combine(guess);
    if (isValid(res)) {
      cout << res;
      exit(0);
    }
    return;
  }
  solve(idx + 1, guess);
  guess[idx] = ')';
  solve(idx + 1, guess);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'G') missing.emplace_back(i);
  }
  string guess(missing.size(), '(');
  solve(0, guess);
  return 0;
}
