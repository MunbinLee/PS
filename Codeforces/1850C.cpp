#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    string res;
    for (int i = 0; i < 8 * 8; i++) {
      char ch;
      cin >> ch;
      if (ch == '.') continue;
      res += ch;
    }
    cout << res << '\n';
  }

  return 0;
}