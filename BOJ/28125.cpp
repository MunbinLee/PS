#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<char, char> mp = {
    {'@', 'a'},
    {'[', 'c'},
    {'!', 'i'},
    {';', 'j'},
    {'^', 'n'},
    {'0', 'o'},
    {'7', 't'}
};

string decrypt(string &s) {
  string res;
  int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (mp[s[i]]) {
      res += mp[s[i]];
      cnt++;
    } else if (s[i] == '\\' && s[i + 1] == '\'') {
      res += 'v';
      cnt++;
      i++;
    } else if (s[i] == '\\' && s[i + 1] == '\\') {
      res += 'w';
      cnt++;
      i += 2;
    } else {
      res += s[i];
    }
  }

  if (cnt >= 1.0 * res.size() / 2) return "I don't understand";
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    cout << decrypt(s) << '\n';
  }

  return 0;
}