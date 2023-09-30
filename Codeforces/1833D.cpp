#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int &i: p) {
    cin >> i;
  }

  int mx = -1;
  int mxIdx = -1;
  for (int i = 1; i < n; i++) {
    if (p[i] > mx) {
      mx = p[i];
      mxIdx = i;
    }
  }

  // 0, mxIdx
  int next = p[mxIdx - 1];
  int l = 0;
  int r = mxIdx;

  // mxIdx, mxIdx
  if (p[0] > next) {
    next = p[0];
    l = mxIdx;
    r = mxIdx;
  }
  int b = p[0];

  // ?, mxIdx - 1


  cout << mx << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}