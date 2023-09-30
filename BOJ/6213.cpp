#include <iostream>
#include <vector>

using namespace std;

int n, q;
vector<int> segTreeMx, segTreeMn;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> q;
  segTreeMx.resize(n * 2);
  segTreeMn.resize(n * 2);
  for (int i = 0; i < n; i++) {
    cin >> segTreeMx[n + i];
    segTreeMn[n + i] = segTreeMx[n + i];
  }
  for (int i = n - 1; i > 0; i--) {
    segTreeMx[i] = max(segTreeMx[i * 2], segTreeMx[i * 2 + 1]);
    segTreeMn[i] = min(segTreeMn[i * 2], segTreeMn[i * 2 + 1]);
  }
}

int query(int start, int end) {
  int mx = -1;
  int mn = INT32_MAX;
  start += n - 1;
  end += n;
  while (start != end) {
    if (start % 2) {
      mx = max(mx, segTreeMx[start]);
      mn = min(mn, segTreeMn[start]);
      start++;
    }
    if (end % 2) {
      end--;
      mx = max(mx, segTreeMx[end]);
      mn = min(mn, segTreeMn[end]);
    }
    start /= 2;
    end /= 2;
  }
  return mx - mn;
}

void solve() {
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << query(a, b) << '\n';
  }
}

int main() {
  input();
  solve();
  return 0;
}
