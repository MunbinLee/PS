#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  for (int &i: v) cin >> i;

  int mx = -1;
  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      for (int k = j + 1; k < n; k++) {
        int sum = v[i] + v[j] + v[k];
        if (sum <= m && sum > mx) mx = sum;
      }
    }
  }
  cout << mx;
  return 0;
}
