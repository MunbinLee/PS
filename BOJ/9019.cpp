#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, string> pr;

char op[] = {'D', 'S', 'L', 'R'};

int convert(int n, int mode) {
  if (mode == 0) {
    return (n * 2 % 10000);
  }
}

string solve(int a, int b) {
  queue<pr> q;
  q.emplace(a, "");
  while (!q.empty()) {
    auto [cur, cmd] = q.front();
    if (cur == b) return cmd;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int next = convert(cur, i);
      string ncmd = cmd + op[i];
      q.emplace(next, ncmd);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << solve(a, b);
  }
  return 0;
}
