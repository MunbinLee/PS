#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  v.resize(n + 1);

  for (int i = 1; i <= n; i++) {
    v[i] = i;
  }

  while (m--) {
    int i, j, k;
    cin >> i >> j >> k;
    auto it = v.begin();
    rotate(it + i, it + k, it + j + 1);
  }

  for (int i = 1; i <= n; i++) {
    cout << v[i] << ' ';
  }
  return 0;
}
