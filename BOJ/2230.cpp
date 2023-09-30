#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  v.resize(n);
  for (int &i: v) cin >> i;
  sort(v.begin(), v.end());
}

int getMinDiff() {
  if (m == 0) return 0;

  int lo = 0;
  int hi = 1;
  int minDiff = INT32_MAX;

  while (hi < n) {
    int diff = v[hi] - v[lo];
    if (diff >= m) {
      minDiff = min(minDiff, diff);
      lo++;
      if (lo == hi) hi++;
    } else {
      hi++;
    }
  }
  return minDiff;
}

int main() {
  input();
  cout << getMinDiff();
  return 0;
}
