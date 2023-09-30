#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i: v) {
    cin >> i;
  }
  sort(v.begin(), v.end());

  int d = lround(n * 0.15);
  double sum = 0;
  for (int i = d; i < n - d; i++) {
    sum += v[i];
  }

  sum /= n - d * 2;
  int res = lround(sum);
  cout << res;
  return 0;
}