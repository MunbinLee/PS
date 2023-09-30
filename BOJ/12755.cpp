#include <iostream>

using namespace std;

char solve(int n) {
  for (int i = 1;; i++) {
    string s = to_string(i);
    for (int j = 0; j < s.size(); j++, n--) {
      if (n == 0) return s[j];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  cout << solve(n - 1);
  return 0;
}
