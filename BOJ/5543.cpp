#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int hamburger = INT32_MAX;
  int drink = INT32_MAX;

  for (int i = 0; i < 3; i++) {
    int tmp;
    cin >> tmp;
    if (tmp < hamburger) hamburger = tmp;
  }

  for (int i = 0; i < 2; i++) {
    int tmp;
    cin >> tmp;
    if (tmp < drink) drink = tmp;
  }

  cout << hamburger + drink - 50;
  return 0;
}
