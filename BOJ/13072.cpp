#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> volumes;

void input() {
  cin >> n >> k;
  volumes.resize(n);
  for (int &i: volumes) {
    cin >> i;
  }
}

bool canDivide(int x) {
  if (!x) return false;

  int cnt = 0;
  for (int volume: volumes) {
    cnt += volume / x;
  }
  return cnt >= k;
}

void solve() {
  int lo = 0;
  int hi = INT32_MAX;
  int res = 0;
  while (lo <= hi) {
    int md = lo + (hi - lo) / 2;
    if (canDivide(md)) {
      res = md;
      lo = md + 1;
    } else {
      hi = md - 1;
    }
  }
  cout << res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  input();
  solve();
}