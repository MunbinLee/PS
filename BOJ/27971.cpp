#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

typedef pair<int, int> pr;

int n, m, a, b;
vector<pr> banned;
unordered_map<int, bool> visited;

bool isBanned(int x) {
  if (visited[x]) return true;
  if (x > n) return true;
  visited[x] = true;
  for (auto [l, r]: banned) {
    if (x >= l && x <= r) return true;
  }
  return false;
}

int bfs() {
  queue<pr> q;
  q.emplace(0, 0);
  while (!q.empty()) {
    auto [cur, cnt] = q.front();
    q.pop();
    if (cur == n) return cnt;
    for (int magic: {a, b}) {
      int next = cur + magic;
      if (isBanned(next)) continue;
      q.emplace(next, cnt + 1);
    }
  }
  return -1;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> a >> b;
  banned.resize(m);
  for (auto &[l, r]: banned) {
    cin >> l >> r;
  }

  cout << bfs();
  return 0;
}
