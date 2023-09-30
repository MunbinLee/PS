#include <iostream>
#include <array>
#include <queue>

#define MAX 100001

using namespace std;

int n, k;
array<bool, MAX> visited;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;
}

bool check(int num, int cnt) {
  if (num >= MAX) return false;
  if (visited[num]) return false;
  visited[num] = true;
  if (num >= k * 2) return false;
  if (num == k) {
    cout << cnt;
    exit(0);
  }
  return true;
}

void getParent() {
  if (n >= k) {
    cout << n - k;
    return;
  }

  queue<pair<int, int>> q; // num, cnt
  check(n, 0);
  q.emplace(n, 0);

  while (!q.empty()) {
    auto [num, cnt] = q.front();
    q.pop();

    int tmp = num * 2;
    while (check(tmp, cnt)) {
      q.emplace(tmp, cnt);
      tmp *= 2;
    }
    if (check(num - 1, cnt + 1)) q.emplace(num - 1, cnt + 1);
    if (check(num + 1, cnt + 1)) q.emplace(num + 1, cnt + 1);
  }
}

int main() {
  input();
  solve();
  return 0;
}
