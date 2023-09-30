#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int sum = 0;
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i: v) {
    cin >> i;
    sum += i;
  }
  sort(v.begin(), v.end());

  int lastNum = v[0];
  int mode;
  int cnt = 1;
  int mxCnt = 1;
  bool isFirst = false;
  for (int i = 1; i < n; i++) {
    if (v[i] == lastNum) cnt++;
    else {
      lastNum = v[i];
      cnt = 1;
    }
    if (cnt > mxCnt) {
      mxCnt = cnt;
      mode = v[i];
      isFirst = true;
    } else if (cnt == mxCnt && isFirst) {
      isFirst = false;
      mode = v[i];
    }
  }

  cout << (int) (round)((double) sum / n) << '\n';
  cout << v[n / 2] << '\n';
  cout << mode << '\n';
  cout << v[n - 1] - v[0];
  return 0;
}
