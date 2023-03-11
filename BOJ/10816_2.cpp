#include <iostream>
#include <algorithm>

using namespace std;

int n;
vector<int> v;

int lowerBound(int num) {
  int low = 0;
  int high = n;
  while (low != high) {
    int mid = (low + high) / 2;
    if (v[mid] < num) low = mid + 1;
    else high = mid;
  }
  return low;
}

int upperBound(int num) {
  int low = 0;
  int high = n;
  while (low != high) {
    int mid = (low + high) / 2;
    if (v[mid] <= num) low = mid + 1;
    else high = mid;
  }
  return low;
}

int getFrequency(int num) {
  int lowerIdx = lowerBound(num);
  int upperIdx = upperBound(num);
  return upperIdx - lowerIdx;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

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
