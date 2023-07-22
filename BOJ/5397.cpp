#include <iostream>
#include <list>

using namespace std;

string decrypt(string &s) {
  list<char> ls;
  auto cursor = ls.begin();

  for (char ch: s) {
    if (ch == '<') {
      if (cursor == ls.begin()) continue;
      cursor--;
    } else if (ch == '>') {
      if (cursor == ls.end()) continue;
      cursor++;
    } else if (ch == '-') {
      if (cursor == ls.begin()) continue;
      auto it = cursor;
      it--;
      ls.erase(it);
    } else {
      ls.emplace(cursor, ch);
    }
  }

  string res(ls.begin(), ls.end());
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    cout << decrypt(s) << '\n';
  }
  return 0;
}