#include <iostream>
#include <array>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  array<int, 100'000> arr{};

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int minDiff = INT_MAX;
  pair<int, int> nearests;
  int lo = 0;
  int hi = n - 1;

  while (lo != hi) {
    int sum = arr[lo] + arr[hi];
    int diff = abs(sum);
    if (diff < minDiff) {
      minDiff = diff;
      nearests = {arr[lo], arr[hi]};
    }
    if (sum < 0) lo++;
    else hi--;
  }

  cout << nearests.first << ' ' << nearests.second;

  return 0;
}
