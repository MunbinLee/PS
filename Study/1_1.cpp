#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i : v) cin >> i;
  int k;
  cin >> k;

  int left = 0;
  int right = n - 1;
  int mnDiff = INT32_MAX;
  int cnt = 0;

  while (left != right) {
    int sum = v[left] + v[right];
    int diff = abs(sum - k);

    if (diff < mnDiff) {
      mnDiff = diff;
      cnt = 1;
    } else if (diff == mnDiff) cnt++;

    (sum > k) ? right-- : left++;
  }

  cout << cnt;
  return 0;
}
