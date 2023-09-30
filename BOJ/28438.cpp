#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, q;
  cin >> n >> m >> q;
  array<vector<int>, 2> v = {
      vector<int>(n),
      vector<int>(m)
  };

  while (q--) {
    int type, key, value;
    cin >> type >> key >> value;
    v[type - 1][key - 1] += value;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << v[0][i] + v[1][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}
