#include <iostream>
#include <vector>

using namespace std;
typedef long long int ll;

ll n, q;
vector<ll> segTree;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> q;
  segTree.resize(n * 2);
  for (ll i = 0; i < n; i++) {
    cin >> segTree[n + i];
  }
  for (ll i = n - 1; i > 0; i--) {
    segTree[i] = segTree[i * 2] + segTree[i * 2 + 1];
  }
}

void update(ll key, ll value) {
  key += n - 1;
  segTree[key] = value;
  while (key /= 2) {
    segTree[key] = segTree[key * 2] + segTree[key * 2 + 1];
  }
}

ll query(ll begin, ll end) {
  if (begin > end) swap(begin, end);
  ll res = 0;
  begin += n - 1;
  end += n;
  while (begin != end) {
    if (begin % 2) {
      res += segTree[begin];
      begin++;
    }
    if (end % 2) {
      end--;
      res += segTree[end];
    }
    begin /= 2;
    end /= 2;
  }
  return res;
}

void solve() {
  while (q--) {
    ll x, y, a, b;
    cin >> x >> y >> a >> b;

    cout << query(x, y) << '\n';
    update(a, b);
  }
}

int main() {
  input();
  solve();
  return 0;
}
