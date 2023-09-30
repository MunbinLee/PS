#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int initMx = -1;
  priority_queue<int, vector<int>, greater<>> pq;

  int n;
  cin >> n;

  while (n--) {
    int num;
    cin >> num;
    initMx = max(initMx, num);
    pq.emplace(num);
  }

  int mx = initMx;
  int mn = pq.top();
  int res = mx - mn;

  while (mn < initMx) {
    pq.pop();
    res = min(res, mx - mn);
    mx = max(mx, mn * 2);
    pq.emplace(mn * 2);
    mn = pq.top();
  }

  cout << res;

  return 0;
}
