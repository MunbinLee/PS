#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
bool isSolved[32001];
vector<int> suf[32001], req[32001];
priority_queue<int, vector<int>, greater<>> pq;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    suf[a].emplace_back(b);
    req[b].emplace_back(a);
  }
}

void solve() {
  for (int i = 1; i <= n; i++) {
    if (req[i].empty()) {
      pq.emplace(i);
    }
  }

  while (!pq.empty()) {
    int cur = pq.top();
    pq.pop();
    cout << cur << ' ';
    isSolved[cur] = true;
    for (int i: suf[cur]) {
      bool isAvailable = true;
      for (int j: req[i]) {
        if (!isSolved[j]) {
          isAvailable = false;
          break;
        }
      }
      if (!isAvailable) continue;
      pq.emplace(i);
    }
  }
}

int main() {
  input();
  solve();
  return 0;
}
