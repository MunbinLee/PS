#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &v) {
  int sz = (int) v.size();
  for (int i = 0; i < sz - 1; i++) {
    for (int j = 0; j < sz - i - 1; j++) {
      if (v[j] <= v[j + 1]) continue;
      swap(v[j], v[j + 1]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i: v) cin >> i;

  bubbleSort(v);

  for (int i: v) cout << i << '\n';
  return 0;
}
