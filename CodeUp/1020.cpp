#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  s.replace(6, 1, "");
  cout << s;
  return 0;
}
