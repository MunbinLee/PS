#include <iostream>

using namespace std;

int l;
string s;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> l >> s;
}

bool match(int n, int start) {
  for (int i = 0; i < n; i++) {
    if (start + i >= l) return true;
    if (s[start + i] != s[i]) return false;
  }
  return true;
}

bool check(int n) {
  for (int i = n; i < l; i += n) {
    if (!match(n, i)) return false;
  }
  return true;
}

int solve() {
  int n = 1;
  while (!check(n)) {
    n++;
  }
  return n;
}

int main() {
  input();
  cout << solve();
  return 0;
}
