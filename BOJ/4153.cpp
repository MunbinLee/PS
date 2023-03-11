#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

array<int, 3> arr;

bool isRightTriangle() {
  for (int &i: arr) {
    cin >> i;
    if (i == 0) return false;
  }
  sort(arr.begin(), arr.end());
  auto [a, b, c] = arr;
  cout << ((a * a + b * b == c * c) ? "right" : "wrong") << '\n';
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  while (isRightTriangle());
  return 0;
}
