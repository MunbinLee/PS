#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int w;
  cin >> w;

  string res = (w % 2 == 0 && w >= 4) ? "YES" : "NO";
  cout << res;
}