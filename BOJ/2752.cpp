#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  array<int, 3> arr;
  for (int &i: arr) cin >> i;
  sort(arr.begin(), arr.end());

  for (int i: arr) cout << i << ' ';
  return 0;
}
