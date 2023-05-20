#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

bool canMakeW() {
  int n;
  cin >> n;
  assert(n >= 2);
  assert(n <= 1000);
  vector<char> colors(n);
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    assert(s.size() == 1);
    assert(s == "W" || s == "P");
    colors[i] = s[0];
  }

  int m, k;
  cin >> m >> k;
  assert(m >= 2);
  assert(m <= 1000);
  assert(k >= 2);
  assert(k <= n);
  while (m--) {
    bool w = true;
    for (int i = 0; i < k; i++) {
      int a;
      cin >> a;
      assert(a >= 1);
      assert(a <= n);
      if (colors[a] == 'P') {
        w = false;
        break;
      } else {
        assert(colors[a] == 'W');
      }
    }
    if (w) return true;
  }
  string str;
  while (cin >> str) {

    assert(!isdigit(str[0]));
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  bool b = canMakeW();
  char res = b ? 'W' : 'P';
  cout << res;
  return 0;
}