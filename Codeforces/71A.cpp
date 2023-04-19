#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  while (n--) {
    string s;
    cin >> s;
    int l = s.length();

    if (l <= 10) cout << s;
    else cout << s[0] << l - 2 << s[l - 1];
    cout << '\n';
  }
}