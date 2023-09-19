#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  string str;
  cin >> str;
  int l = 0;
  int s = 0;
  int cnt = 0;

  for (int i = 0; i < n; i++) {
    char c = str[i];
    if (c >= '1' && c <= '9') cnt++;
    else if (c == 'L') l++;
    else if (c == 'R') {
      l--;
      if (l < 0) break;
      cnt++;
    } else if (c == 'S') s++;
    else if (c == 'K') {
      s--;
      if (s < 0) break;
      cnt++;
    }
  }
  cout << cnt;
  return 0;
}
