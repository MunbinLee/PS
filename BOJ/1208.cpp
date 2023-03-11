#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, s, res;
vector<int> v;

void solve(int idx, int sum, bool isEmpty) {
  if (idx == n && sum == s && !isEmpty) {
    res++;
    return;
  }
  if (idx == n) return;
  solve(idx + 1, sum, isEmpty);
  solve(idx + 1, sum + v[idx], false);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> s;
  v.resize(n);
  for (int &i: v) cin >> i;
  sort(v.begin(), v.end());
  solve(0, 0, true);
  cout << res;
  return 0;
}
