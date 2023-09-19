#include <iostream>
#include <queue>

using namespace std;

int bfs(int a, int b) {
  queue<pair<int, int>> q;
  q.emplace(a, 1);

  while (!q.empty()) {
    auto p = q.front();
    q.pop();
    if (p.first == b) return p.second;
    if (p.first > b) continue;
    if (p.first <= 500000000) q.emplace(p.first * 2, p.second + 1);
    if (p.first < 100000000) q.emplace(p.first * 10 + 1, p.second + 1);
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b;
  cin >> a >> b;
  cout << bfs(a, b);
  return 0;
}
