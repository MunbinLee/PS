#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int solve(int left, int right) {
  if (left == right) return v[left];
  int mid = (left + right) / 2;

  int res = max(solve(left, mid), solve(mid + 1, right));

  int lo = mid;
  int hi = mid + 1;
  int height = min(v[lo], v[hi]);
  res = max(res, height * 2);

  while (left < lo || hi < right) {
    if (hi < right && (lo == left || v[lo - 1] < v[hi + 1])) {
      hi++;
      height = min(height, v[hi]);
    } else {
      lo--;
      height = min(height, v[lo]);
    }
    res = max(res, height * (hi - lo + 1));
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while (n) {
    v = vector<int>(n);
    for (int &i: v) {
      cin >> i;
    }
    cout << solve(0, n - 1);
    cin >> n;
  }
  return 0;
}
