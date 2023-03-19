#include <iostream>
#include <vector>

#define div 1000000007

using namespace std;
typedef long long int ll;

int n, m, k;
vector<ll> segTree;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> k;
  segTree.resize(n * 2);
  for (int i = 0; i < n; i++) {
    cin >> segTree[n + i];
  }
  for (int i = n - 1; i > 0; i--) {
    segTree[i] = segTree[i * 2] * segTree[i * 2 + 1];
    segTree[i] %= div;
  }
}

void update(int key, int value) {
  key += n - 1;
  segTree[key] = value;
  while (key /= 2) {
    segTree[key] = segTree[key * 2] * segTree[key * 2 + 1];
    segTree[key] %= div;
  }
}

ll query(int begin, int end) {
  ll res = 1;
  begin += n - 1;
  end += n;
  while (begin != end) {
    if (begin % 2) {
      res *= segTree[begin];
      res %= div;
      begin++;
    }
    if (end % 2) {
      end--;
      res *= segTree[end];
      res %= div;
    }
    begin /= 2;
    end /= 2;
  }
  return res;
}

void solve() {
  int q = m + k;
  while (q--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1) update(b, c);
    else if (a == 2) cout << query(b, c) << '\n';
  }
}

int main() {
  input();
  solve();
  return 0;
}
