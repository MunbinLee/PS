#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<int> v;
priority_queue<pair<double, int>> pq; // 가중치, 길이

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  v = vector<int>(n + 1);
  for (int i = 1; i <= n; i++) {
    int value;
    cin >> value;
    v[i] = value;
    pq.emplace((double) value / i, i);
  }
}

int getBestIdx() {
  int idx = pq.top().second;
  while (idx > n) {
    pq.pop();
    idx = pq.top().second;
  }
  return idx;
}

void solve() {
  int money = 0;
  while (n) {
    int idx = getBestIdx();
    n -= idx;
    money += v[idx];
  }
  cout << money;
}

int main() {
  input();
  solve();
  return 0;
}
