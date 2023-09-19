#include <iostream>
#include <array>

using namespace std;

int main() {
  array<int, 8> arr;

  for (int &i: arr) {
    cin >> i;
  }

  array<int, 8> ascend = {1, 2, 3, 4, 5, 6, 7, 8};
  array<int, 8> descend = {8, 7, 6, 5, 4, 3, 2, 1};

  string res;

  if (arr == ascend) res = "ascending";
  else if (arr == descend) res = "descending";
  else res = "mixed";

  cout << res;
  return 0;
}
