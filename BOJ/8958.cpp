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
    int tmp = 0;
    int res = 0;

    for (char c: s) {
      if (c == 'O') {
        tmp++;
        res += tmp;
      } else tmp = 0;

    }

    cout << res << '\n';
  }
  return 0;
}
