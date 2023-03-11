#include <iostream>
#include <queue>

using namespace std;

int n, l, tmp;
deque<pair<int, int>> dq;

void solve() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> l;

  for (int i = 0; i < n; i++) {
    if (!dq.empty() && dq.front().second < i - l + 1) dq.pop_front();
    cin >> tmp;
    while (!dq.empty() && dq.back().first > tmp) dq.pop_back();
    dq.emplace_back(tmp, i);
    cout << dq.front().first << ' ';
  }
}

int main() {
  solve();
  return 0;
}
