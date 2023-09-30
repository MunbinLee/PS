#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int, int> pr; // 값, 인덱스

vector <pr> v;
vector<int> res;

void input() {
  int n;
  cin >> n;
  v.resize(n);
  res.resize(n);
  for (int i = 0; i < n; i++) {
    int value;
    cin >> value;
    v[i] = {value, i};
  }
  sort(v.begin(), v.end());
}

void solve() {
  int cnt = -1;
  int prev = INT32_MAX;
  for (auto &[cur, idx]: v) {
    if (cur != prev) cnt++;
    prev = cur;
    res[idx] = cnt;
  }

  for (int i: res) {
    cout << i << ' ';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  input();
  solve();
  return 0;
}
