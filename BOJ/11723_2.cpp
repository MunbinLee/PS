#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int mask = 0;

  int m;
  cin >> m;

  while (m--) {
    string op;
    cin >> op;
    if (op == "add") {
      int num;
      cin >> num;
      mask |= 1 << num;
    } else if (op == "remove") {
      int num;
      cin >> num;
      mask &= ~(1 << num);
    } else if (op == "check") {
      int num;
      cin >> num;
      cout << ((mask & (1 << num)) != 0) << '\n';
    } else if (op == "toggle") {
      int num;
      cin >> num;
      mask ^= 1 << num;
    } else if (op == "all") {
      mask = (1 << 21) - 1;
    } else { // empty
      mask = 0;
    }
  }

  return 0;
}
