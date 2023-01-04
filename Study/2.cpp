#include <iostream>
#include <vector>
using namespace std;

int floor(int n, int k, const vector<int> &v) {
  int left = 0;
  int right = n - 1;

  while (left <= right) {
    int mid = (left + right) / 2;
    if (v[mid] <= k and (mid == n - 1 || v[mid + 1] > k)) return v[mid];
    if (v[mid] < k) left = mid + 1;
    else right = mid - 1;
  }
  return -1;
}

int ceiling(int n, int k, const vector<int> &v) {
  int left = 0;
  int right = n - 1;

  while (left <= right) {
    int mid = (left + right) / 2;
    if (v[mid] >= k and (mid == 0 || v[mid - 1] < k)) return v[mid];
    if (v[mid] < k) left = mid + 1;
    else right = mid - 1;
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i : v) cin >> i;
  int k;
  cin >> k;

  cout << floor(n, k, v) << '\n' << ceiling(n, k, v);
  return 0;
}
