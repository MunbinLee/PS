#include <iostream>
#include <vector>

using namespace std;

int n, q;
vector<int> segTree;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  segTree.resize(n * 2);
  for (int i = 0; i < n; i++) {
    cin >> segTree[n + i];
  }
  for (int i = n - 1; i > 0; i--) {
    segTree[i] = min(segTree[i * 2], segTree[i * 2 + 1]);
  }
  cin >> q;
}

void update(int key, int value) {
  key += n - 1;
  segTree[key] = value;
  while (key /= 2) {
    segTree[key] = min(segTree[key * 2], segTree[key * 2 + 1]);
  }
}

int query(int start, int end) {
  int mn = INT32_MAX;
  start += n - 1;
  end += n;
  while (start != end) {
    if (start % 2) {
      mn = min(mn, segTree[start]);
      start++;
    }
    if (end % 2) {
      end--;
      mn = min(mn, segTree[end]);
    }
    start /= 2;
    end /= 2;
  }
  return mn;
}

void solve() {
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
