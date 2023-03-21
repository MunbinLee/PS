#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long int ll;

ll mn, mx;
vector<bool> isSquareFree;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> mn >> mx;
  isSquareFree.assign(mx - mn + 1, true);
}

int numToIdx(ll n) {
  return (int) (n - mn);
}

void solve() {
  for (ll i = 2; i * i <= mx; i++) {
    for (ll j = ceil((double) mn / (double) i / (double) i); i * i * j <= mx; j++) {
      int idx = numToIdx(i * i * j);
      isSquareFree[idx] = false;
    }
  }

  int cnt = 0;
  for (bool b: isSquareFree) {
    if (b) cnt++;
  }
  cout << cnt;
}

int main() {
  input();
  solve();
  return 0;
}
