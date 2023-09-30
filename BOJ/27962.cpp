#include <iostream>

using namespace std;

int n;
string s;

bool check(int len) {
  int lo = 0;
  int hi = n - len;
  int cnt = 0;

  while (hi != n) {
    if (s[lo] != s[hi]) cnt++;
    lo++;
    hi++;
  }
  return cnt == 1;
}

bool solve() {
  for (int i = 1; i < n; i++) {
    if (check(i)) return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> s;
  string res = solve() ? "YES" : "NO";
  cout << res;
  return 0;
}
