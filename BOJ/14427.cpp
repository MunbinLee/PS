#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pr;

int n, m;
vector<pr> segTree; // 최솟값, 인덱스

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  segTree.resize(n * 2);
  for (int i = 1; i <= n; i++) {
    int tmp;
    cin >> tmp;
    segTree[n + i - 1] = {tmp, i};
  }
  for (int i = n - 1; i > 0; i--) {
    segTree[i] = min(segTree[i * 2], segTree[i * 2 + 1]);
  }
  cin >> m;
}

void update(int key, int value) {
  key += n - 1;
  segTree[key] = {value, key - n + 1};
  while (key /= 2) {
    segTree[key] = min(segTree[key * 2], segTree[key * 2 + 1]);
  }
}

int query(int start, int end) {
  pr res = {INT32_MAX, INT32_MAX};
  start += n - 1;
  end += n;
  while (start != end) {
    if (start % 2) {
      res = min(res, segTree[start]);
      start++;
    }
    if (end % 2) {
      end--;
      res = min(res, segTree[end]);
    }
    start /= 2;
    end /= 2;
  }
  return res.second;
}

void solve() {
  while (m--) {
    int a;
    cin >> a;
    if (a == 1) {
      int b, c;
      cin >> b >> c;
      update(b, c);
    } else if (a == 2) {
      cout << query(1, n) << '\n';
    }
  }
}

int main() {
  input();
  solve();
  return 0;
}
