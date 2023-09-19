#include <iostream>
#include <vector>

using namespace std;

int floor(int n, int k, const vector<int> &v) {
  int left = 0;
  int right = n - 1;

  while (left <= right) {
    int mid = (left + right) / 2;
    if (v[mid] <= k && (mid == n - 1 || v[mid + 1] > k)) return v[mid];
    // v[mid]가 가장 오른쪽에 있는 수이고 k 이하이면 return
    // v[mid]가 k 이하이고 v[mid+1]가 k 초과이면 return

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
    // v[mid]가 가장 왼쪽에 있는 수이고 k 이상이면 return
    // v[mid]가 k 이상이고 v[mid+1]가 k 미만이면 return

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
  for (int &i: v) cin >> i;
  int k;
  cin >> k;

  cout << floor(n, k, v) << '\n' << ceiling(n, k, v);
  return 0;
}
