#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v;

bool isAvailable(int maxCapacity) {
  int cnt = 1;
  int capacity = maxCapacity;
  for (int i: v) {
    if (i > maxCapacity) return false;

    if (i > capacity) {
      cnt++;
      if (cnt > m) return false;
      capacity = maxCapacity;
    }
    capacity -= i;
  }
  return true;
}

int binarySearch() {
  int lo = 1;
  int hi = 1000000000;
  int res;
  while (lo <= hi) {
    int md = (lo + hi) / 2;
    if (isAvailable(md)) {
      res = md;
      hi = md - 1;
    } else {
      lo = md + 1;
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  v.resize(n);
  for (int &i: v) {
    cin >> i;
  }
  cout << binarySearch();
  return 0;
}