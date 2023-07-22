#include <iostream>

using namespace std;

int reverse(int x) {
  string s = to_string(x);
  reverse(s.begin(), s.end());
  return stol(s);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int d;
  cin >> d;
  for (int i = 0; i < INT32_MAX; i++) {
    if (i - reverse(i) == d) {
      cout << i;
      return 0;
    }
  }
  return 1;
}