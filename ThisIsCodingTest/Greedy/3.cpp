#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  int mx = -1;
  for (int i = 0; i < n; i++) {
    int mn = INT32_MAX;
    for (int j = 0; j < m; j++) {
      int num;
      cin >> num;
      mn = min(mn, num);
    }
    mx = max(mx, mn);
  }

  cout << mx;

  return 0;
}