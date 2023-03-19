#include <iostream>
#include <vector>

using namespace std;
typedef long long int ll;

ll n, m, k;
vector<ll> segTree, lazy;
vector<int> child;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> k;
  segTree.resize(n * 2);
  lazy.resize(n * 2);
  child.resize(n * 2);
  for (ll i = 0; i < n; i++) {
    cin >> segTree[n + i];
    child[n + i] = 1;
  }
  for (ll i = n - 1; i > 0; i--) {
    segTree[i] = segTree[i * 2] + segTree[i * 2 + 1];
    child[i] = child[i * 2] + child[i * 2 + 1];
  }
}

void propagate(ll node) {
  if (lazy[node] == 0) return;

  segTree[node] += lazy[node] * child[node];
  if (node < n) { // 리프 노드가 아닐 경우 자식에 전달
    lazy[node * 2] += lazy[node];
    lazy[node * 2 + 1] += lazy[node];
  }
  lazy[node] = 0;
}

void update(ll start, ll end, ll value) {
  start += n - 1;
  end += n;
  while (start != end) {
    if (start % 2) {
      propagate(start);
      lazy[start] += value;
      start++;
    }
    if (end % 2) {
      end--;
      propagate(end);
      lazy[end]+=value;
    }
    start /= 2;
    end /= 2;
  }
}

ll query(ll start, ll end) {
  ll res = 0;
  start += n - 1;
  end += n;
  while (start != end) {
    if (start % 2) {
      propagate(start);
      res += segTree[start];
      start++;
    }
    if (end % 2) {
      end--;
      propagate(end);
      res += segTree[end];
    }
    start /= 2;
    end /= 2;
  }
  return res;
}

void solve() {
  ll q = m + k;
  while (q--) {
    ll a, b, c, d;
    cin >> a >> b >> c;
    if (a == 1) {
      cin >> d;
      update(b, c, d);
    } else if (a == 2) {
      cout << query(b, c) << '\n';
    }
  }
}

int main() {
  input();
  solve();
  return 0;
}
