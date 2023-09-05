#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int res = 0;

  for (int i = 0; i < 5; i++) {
    int num;
    cin >> num;
    res ^= num;
  }

  cout << res;

  return 0;
}
