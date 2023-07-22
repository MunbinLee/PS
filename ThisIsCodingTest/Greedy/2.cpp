#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  vector<int> v(n);
  for (int &i: v) {
    cin >> i;
  }
  sort(v.begin(), v.end(), greater<>());

  int count = m / (k + 1) * k;
  int res = v[0] * count;
  res += v[1] * (m - count);

  cout << res;

  return 0;
}
