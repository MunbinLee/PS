#include <iostream>
#include <algorithm>

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

  sort(v.begin(), v.end(), greater<>());

  for (int i: v) {
    cout << i << ' ';
  }

  return 0;
}
