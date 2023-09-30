#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int &i: v) {
      cin >> i;
    }
    sort(v.begin(), v.end());

    int curConsecutive = 0;
    int maxConsecutive = 0;
    int prev = v[0];

    for (int i: v) {
      int diff = abs(i - prev);
      if (diff <= k) {
        curConsecutive++;
        maxConsecutive = max(maxConsecutive, curConsecutive);
      } else {
        curConsecutive = 1;
      }
      prev = i;
    }

    int res = n - maxConsecutive;
    cout << res << '\n';
  }

  return 0;
}