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
    segTree[i] = min(segTree[i * 2], segTree[i * 2 + 1]);
  }
}

void update(int key, int value) {
  key += n - 1;
  segTree[key] = value;
  while (key /= 2) {
    segTree[key] = min(segTree[key * 2], segTree[key * 2 + 1]);
  }
}

int query(int begin, int end) {
  int res = INT32_MAX;
  begin += n - 1;
  end += n;
  while (begin != end) {
    if (begin % 2) {
      res = min(res, segTree[begin]);
      begin++;
    }
    if (end % 2) {
      end--;
      res = min(res, segTree[end]);
    }
    begin /= 2;
    end /= 2;
  }
  return res;
}

void solve() {
  while (m--) {
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
