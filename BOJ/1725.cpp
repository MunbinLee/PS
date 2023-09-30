#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;

void input() {
  cin >> n;
  v.resize(n);
  for (int &i: v) {
    cin >> i;
  }
}

void solve() {
  int lo = 0;
  int hi = n - 1;
  int maxArea = 0;

  while (lo < hi) {
    int area = (hi - lo) * min(v[lo], v[hi]);
    if (area > maxArea)
      maxArea = max(maxArea, area);
    (v[lo] < v[hi]) ? lo++ : hi--;
  }

  cout << maxArea;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  input();
  solve();
  return 0;
}
