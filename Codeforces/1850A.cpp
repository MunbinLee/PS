#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    array<int, 3> arr{};
    for (int &i: arr) {
      cin >> i;
    }
    sort(arr.begin(), arr.end(), greater<>());
    bool exists = arr[0] + arr[1] >= 10;
    string res = exists ? "YES" : "NO";
    cout << res << '\n';
  }

  return 0;
}