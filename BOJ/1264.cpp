#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  while (true) {
    int cnt = 0;
    string s;
    getline(cin, s);
    for (char c: s) {
      if (c == '#') return 0;
      if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') cnt++;
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++;
    }
    cout << cnt << '\n';
  }
}
