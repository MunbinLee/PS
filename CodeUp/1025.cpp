#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;

  for (int i = 0; i < 5; i++) {
    cout << '[' << s[i];
    for (int j = 0; j < 4 - i; j++) cout << '0';
    cout << "]\n";
  }
  return 0;
}
