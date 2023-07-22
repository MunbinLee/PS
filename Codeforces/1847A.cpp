#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> diffs(n - 1);
    int sum = 0;
    int prev;
    cin >> prev;
    for (int &i: diffs) {
      int cur;
      cin >> cur;
      i = abs(cur - prev);
      sum += i;
      prev = cur;
    }
    sort(diffs.begin(), diffs.end(), greater<>());
    for (int i = 0; i < k - 1; i++) {
      sum -= diffs[i];
    }
    cout << sum << '\n';
  }

  return 0;
}