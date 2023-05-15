#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> v(n + 1);
  for (int i = 1; i <= n; i++) {
    v[i] = i;
  }

  while (m--) {
    int i, j;
    cin >> i >> j;
    auto it = v.begin();
    reverse(it + i, it + j + 1);
  }

  for (int i = 1; i <= n; i++) {
    cout << v[i] << ' ';
  }

  return 0;
}
