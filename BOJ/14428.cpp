#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pr; // 최솟값, 최소 인덱스

int n, m;
vector<pr> segTree;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  segTree.resize(n * 2);
  for (int i = 0; i < n; i++) {
    cin >> segTree[n + i].first;
    segTree[n + i].second = i + 1;
  }
  for (int i = n - 1; i > 0; i--) {
    segTree[i] = min(segTree[i * 2], segTree[i * 2 + 1]);
  }
  cin >> m;
}

void update(int key, int value) {
  key += n - 1;
  segTree[key].first = value;
  while (key /= 2) {
    segTree[key] = min(segTree[key * 2], segTree[key * 2 + 1]);
  }
}

int query(int begin, int end) {
  pr res = {INT32_MAX, INT32_MAX};
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
  return res.second;
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
