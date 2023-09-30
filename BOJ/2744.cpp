#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  for (char &c: s) {
    if (isupper(c)) c = tolower(c);
    else c = toupper(c);
  }

  cout << s;
  return 0;
}
