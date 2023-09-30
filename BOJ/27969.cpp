#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int res = 0;
  string s;
  while (cin >> s) {
    if (s[0] == '[' || isdigit(s[0])) res += 8;
    else if (s[0] != ']') res += s.size() + 12;
  }

  cout << res;
  return 0;
}
