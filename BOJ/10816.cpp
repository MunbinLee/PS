#include <iostream>
#include <algorithm>

using namespace std;

vector<int> v;

int getFrequency(int num) {
  return (int) (upper_bound(v.begin(), v.end(), num) - lower_bound(v.begin(), v.end(), num));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  v.resize(n);
  for (int &i: v) cin >> i;
  sort(v.begin(), v.end());

  int m;
  cin >> m;
  while (m--) {
    int num;
    cin >> num;
    cout << getFrequency(num) << ' ';
  }
  return 0;
}
