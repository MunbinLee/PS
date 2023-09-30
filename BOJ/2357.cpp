#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> segTreeMn, segTreeMx;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  segTreeMn.resize(n * 2);
  segTreeMx.resize(n * 2);
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    segTreeMn[n + i] = tmp;
    segTreeMx[n + i] = tmp;
  }
  for (int i = n - 1; i > 0; i--) {
    segTreeMn[i] = min(segTreeMn[i * 2], segTreeMn[i * 2 + 1]);
    segTreeMx[i] = max(segTreeMx[i * 2], segTreeMx[i * 2 + 1]);
  }
}

pair<int, int> query(int begin, int end) {
  int mn = INT32_MAX;
  int mx = -1;
  begin += n - 1;
  end += n;
  while (begin != end) {
    if (begin % 2) {
      mn = min(mn, segTreeMn[begin]);
      mx = max(mx, segTreeMx[begin]);
      begin++;
    }
    if (end % 2) {
      end--;
      mn = min(mn, segTreeMn[end]);
      mx = max(mx, segTreeMx[end]);
    }
    begin /= 2;
    end /= 2;
  }
  return {mn, mx};
}

void solve() {
  while (m--) {
    int a, b;
    cin >> a >> b;
    auto [mn, mx] = query(a, b);
    cout << mn << ' ' << mx << '\n';
  }
}

int main() {
  input();
  solve();
  return 0;
}
