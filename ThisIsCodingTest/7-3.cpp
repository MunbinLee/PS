#include <iostream>
#include <vector>

using namespace std;

int getLength(int cutter, vector<int> &v) {
  int res = 0;
  for (int i: v) {
    if (i <= cutter) continue;
    res += i - cutter;
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> v(m);
  for (int &i: v) {
    cin >> i;
  }

  int lo = 0;
  int hi = 1e9;
  int res = -1;
  while (lo <= hi) {
    int md = lo + (hi - lo) / 2;
    int length = getLength(md, v);
    if (length >= m) {
      res = md;
      lo = md + 1;
    } else {
      hi = md - 1;
    }
  }

  cout << res;

  return 0;
}