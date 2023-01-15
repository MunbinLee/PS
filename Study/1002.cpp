// O(N) 풀이

#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i : v) cin >> i;

  while (true) {
    int i, j;
    cin >> i >> j;
    if (i == -1) break;
    int mn = INT32_MAX;
    for (int k = i; k <= j; k++) {
      if (v[k] < mn) mn = v[k];
    }
    cout << mn << '\n';
  }
  return 0;
}
