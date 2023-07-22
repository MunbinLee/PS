#include <iostream>
#include <queue>
#include <array>

using namespace std;

typedef pair<int, string> pr;

char op[] = {'D', 'S', 'L', 'R'};

int convert(int n, int mode) {
  if (mode == 0) {
    n *= 2;
    n %= 10000;
  }
  if (mode == 1) {
    if (!n) n = 9999;
    else n -= 1;
  }
  if (mode == 2) {
    n *= 10;
    n += n / 10000;
    n %= 10000;
  }
  if (mode == 3) {
    n += n % 10 * 10000;
    n /= 10;
  }
  return n;
}

string solve(int from, int to) {
  array<bool, 10000> visited{};
  visited[from] = true;
  queue<pr> q;
  q.emplace(from, "");
  while (!q.empty()) {
    auto [cur, cmd] = q.front();
    if (cur == to) return cmd;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int next = convert(cur, i);
      if (visited[next]) continue;
      visited[next] = true;
      string nCmd = cmd + op[i];
      q.emplace(next, nCmd);
    }
  }
  return {};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << solve(a, b) << '\n';
  }
  return 0;
}
