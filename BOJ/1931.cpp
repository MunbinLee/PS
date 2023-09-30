#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> v;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.second == b.second) return a.first < b.first;
  return a.second < b.second;
}

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  v = vector<pair<int, int>>(n);
  for (auto &i: v) {
    cin >> i.first >> i.second;
  }
  sort(v.begin(), v.end(), cmp);
}

void solve() {
  int endTime = 0;
  int cnt = 0;
  for (auto i: v) {
    if (i.first >= endTime) {
      endTime = i.second;
      cnt++;
    }
  }
  cout << cnt;
}

int main() {
  input();
  solve();
  return 0;
}
