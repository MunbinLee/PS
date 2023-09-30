#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_map>

using namespace std;

typedef pair<int, int> pr;
typedef tuple<int, pr, string> tp;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
pr z;
string s(9, '0');
string target = "123456780";

pr int2pr(int n) {
  int y = n / 3;
  int x = n % 3;
  return {y, x};
}

int pr2int(pr p) {
  auto [y, x] = p;
  return y * 3 + x;
}

void input() {
  for (int i = 0; i < 9; i++) {
    cin >> s[i];
    if (s[i] == '0') {
      z = int2pr(i);
    }
  }
}

string moveBoard(int y, int x, int ny, int nx, string str) {
  int c = pr2int({y, x});
  int n = pr2int({ny, nx});
  swap(str[c], str[n]);
  return str;
}

int solve() {
  unordered_map<string, bool> visited;
  visited[s] = true;

  queue<tp> q;
  q.emplace(0, z, s);

  while (!q.empty()) {
    auto [cnt, zero, cur] = q.front();
    auto [y, x] = zero;
    q.pop();
    if (cur == target) return cnt;
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny == -1 || ny == 3 || nx == -1 || nx == 3) continue;
      string next = moveBoard(y, x, ny, nx, cur);
      if (visited[next]) continue;
      visited[next] = true;
      pr nz = {ny, nx};
      q.emplace(cnt + 1, nz, next);
    }
  }

  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  input();
  cout << solve();
  return 0;
}