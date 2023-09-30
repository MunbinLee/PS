#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  int res = 0;

  while (cin >> s) {
    res++;
  }

  cout << res;
  return 0;
}
