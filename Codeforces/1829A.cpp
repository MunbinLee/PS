#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  string base = "codeforces";
  while (t--) {
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < 10; i++) {
      if (base[i] != s[i]) cnt++;
    }
    cout << cnt << '\n';
  }
}