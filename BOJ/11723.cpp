#include <iostream>
#include <array>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  array<bool, 21> arr{};

  int m;
  cin >> m;

  while (m--) {
    string op;
    cin >> op;
    if (op == "add") {
      int num;
      cin >> num;
      arr[num] = true;
    } else if (op == "remove") {
      int num;
      cin >> num;
      arr[num] = false;
    } else if (op == "check") {
      int num;
      cin >> num;
      cout << arr[num] << '\n';
    } else if (op == "toggle") {
      int num;
      cin >> num;
      arr[num] ^= true;
    } else if (op == "all") {
      arr.fill(true);
    } else { // empty
      arr.fill(false);
    }
  }

  return 0;
}
