#include <iostream>
#include <vector>
using namespace std;

int floor(int n, int k, vector<int> &v) {
  int left = 0;
  int right = n - 1;
  while (left + 1 < right) {
    int mid = (left + right) / 2;
    if (v[mid] > k && v[mid - 1] <= k) {
      return mid - 1;
    }
    left = mid;
  }
  return -1;
}

int ceiling(int n, int k, vector<int> &v) {
  int left = 0;
  int right = n - 1;
  while (left < right) {
    int mid = (left + right) / 2;
    if (v[mid] < k && v[mid - 1] >= k) {
      return mid - 1;
    }
    right = mid;
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
