#include <vector>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int c;
  cin >> c;

  while (c--) {
    int n, l;
    cin >> n >> l;
    vector<int> v(n);
    for (int &i: v) cin >> i;
    double mn = 100000.0;
    cout << fixed;
    cout.precision(8);

    for (int i = 0; i + l <= n; i++) {
      int sum = 0;
      for (int j = i; j < n; j++) {
        sum += v[j];
        int cnt = j - i + 1;
        if (cnt >= l) {
          double tmp = (double) sum / cnt;
          if (tmp < mn) mn = tmp;
        }
      }
    }
    cout << mn << '\n';
  }
  return 0;
}
