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
  int cnts[8001] = {};
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    sum += num;
    cnts[num + 4000]++;
  }

  int mxCnt = 0;
  int mode;
  int isFirst = false;
  for (int i = 0; i <= 8000; i++) {
    if (cnts[i] > mxCnt) {
      mxCnt = cnts[i];
      mode = i - 4000;
      isFirst = true;
    } else if (cnts[i] == mxCnt && isFirst) {
      isFirst = false;
      mode = i - 4000;
    }
  }

  cout << (int) (round)((double) sum / n) << '\n';
  cout << v[n / 2] << '\n';
  cout << mode << '\n';
  cout << v[n - 1] - v[0];
  return 0;
}
