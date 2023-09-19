#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i: v) cin >> i;

  int m = (int) sqrt(n);
  int numOfGroups = ceil((double) n / m);
  vector<int> mnOfGroup(numOfGroups, INT32_MAX);
  for (int i = 0; i < n; i++) {
    int group = (int) (i / m);
    if (v[i] < mnOfGroup[group]) mnOfGroup[group] = v[i];
  }

  while (true) {
    int i, j;
    cin >> i >> j;
    if (i == -1) break;
    if (i == j) {
      cout << v[i] << '\n';
      continue;
    }

    int mn = INT32_MAX;
    int ig = (int) (i / m);
    int jg = (int) (j / m);

    for (int k = i; k < (ig + 1) * m && k <= j; k++) {
      if (v[k] < mn) mn = v[k];
    }

    if (ig != jg) {
      for (int k = ig + 1; k < jg; k++) {
        if (mnOfGroup[k] < mn) mn = mnOfGroup[k];
      }

      for (int k = jg * m; k <= j; k++) {
        if (v[k] < mn) mn = v[k];
      }
    }

    cout << mn << '\n';
  }
  return 0;
}
