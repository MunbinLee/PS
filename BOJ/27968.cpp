#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

int n, m;
vector<ll> prefSum;

void binarySearch(ll x) {
  int lo = 0;
  int hi = m - 1;
  int res = -1;
  while (lo <= hi) {
    int md = (lo + hi) / 2;
    if (prefSum[md] >= x) {
      res = md;
      hi = md - 1;
    } else {
      lo = md + 1;
    }
  }
  if (res == -1) cout << "Go away!\n";
  else cout << res + 1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  prefSum.resize(m);
  ll sum = 0;
  for (ll &i: prefSum) {
    cin >> i;
    i += sum;
    sum = i;
  }
  while (n--) {
    ll x;
    cin >> x;
    binarySearch(x);
  }
  return 0;
}
