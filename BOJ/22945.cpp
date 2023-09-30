#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  v.resize(n);
  for (int &i: v) {
    cin >> i;
  }

  int lo = 0;
  int hi = n - 1;
  int maxStat = -1;

  while (lo < hi) {
    int stat = (hi - lo - 1) * min(v[lo], v[hi]);
    maxStat = max(maxStat, stat);
    if (v[lo] < v[hi]) {
      lo++;
    } else {
      hi--;
    }
  }

  cout << maxStat;

  return 0;
}
