#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i: v) {
    cin >> i;
  }

  int lo = 0;
  int hi = 0;
  int maxHeight = 0;
  while (hi < n) {
    int height = hi - lo + 1;
    if (v[hi] >= height) {
      maxHeight = max(maxHeight, height);
      hi++;
    } else {
      lo++;
      hi = max(lo, hi--);
    }
  }
  cout << maxHeight;
  return 0;
}
