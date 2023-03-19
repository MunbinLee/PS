#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> segTree;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  segTree.resize(n * 2);
  for (int i = 0; i < n; i++) {
    cin >> segTree[n + i];
  }
  for (int i = n - 1; i > 0; i--) {
    segTree[i] = segTree[i * 2] + segTree[i * 2 + 1];
  }
}

void update(int key, int value) {
  key += n - 1;
  segTree[key] = value;
  while (key /= 2) {
    segTree[key] = segTree[key * 2] + segTree[key * 2 + 1];
  }
}

int query(int start, int end) {
  int res = 0;
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
    else if (a == 2) cout << query(b, c) << '\n';
  }
}

int main() {
  input();
  solve();
  return 0;
}
