#include <iostream>
#include <vector>

using namespace std;
typedef long long int ll;

int n, m;
vector<ll> segTree;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  segTree.resize(n * 2);
}

void update(int key, int value) {
  key += n - 1;
  segTree[key] = value;
  while (key /= 2) {
    segTree[key] = segTree[key * 2] + segTree[key * 2 + 1];
  }
}

ll query(int start, int end) {
  if (start > end) swap(start, end);
  ll res = 0;
  start += n - 1;
  end += n;
  while (start != end) {
    if (start % 2) {
      res += segTree[start];
      start++;
    }
    if (end % 2) {
      end--;
      res += segTree[end];
    }
    start /= 2;
    end /= 2;
  }
  return res;
}

void solve() {
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1) update(b, c);
    else if (a == 0) cout << query(b, c) << '\n';
  }
}

int main() {
  input();
  solve();
  return 0;
}
