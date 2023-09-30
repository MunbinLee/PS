#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector <pair<int, int>> v(n);
  for (auto &i: v) {
    cin >> i.second >> i.first;
  }
  sort(v.begin(), v.end());

  for (auto i: v) {
    cout << i.second << ' ' << i.first << '\n';
  }
  return 0;
}
