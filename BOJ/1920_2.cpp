#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i: v) cin >> i;
  sort(v.begin(), v.end());

  int m;
  cin >> m;

  while (m--) {
    int tmp;
    cin >> tmp;
    cout << binary_search(v.begin(), v.end(), tmp) << '\n';
  }
  return 0;
}
