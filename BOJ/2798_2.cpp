#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;

// value 이하인 최댓값을 찾는다.
int binarySearch(int low, int high, int value) {
  if (v[high] <= value) return v[high];
  int res = -1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (v[mid] == value) return value;
    if (v[mid] < value) {
      res = v[mid];
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  v = vector<int>(n);
  for (int &i: v) cin >> i;
  sort(v.begin(), v.end());

  int mx = -1;
  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      int sum = v[i] + v[j];
      if (sum >= m) continue;
      sum += binarySearch(j + 1, n - 1, m - sum);
      if (sum > mx) mx = sum;
    }
  }
  cout << mx;
  return 0;
}
