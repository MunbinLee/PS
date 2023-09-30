#include <iostream>

using namespace std;

int n;
int maxCnt = 2;
int price[15][15]; // 판매자, 구매자
bool memo[15][10][1 << 15]; // 소유자, 가격, 방문 비트

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++) {
      price[i][j] = s[j] - '0';
    }
  }
}

int brianKernighan(int bit) {
  int cnt = 0;
  while (bit != 0) {
    bit = bit & (bit - 1);
    cnt++;
  }
  return cnt;
}

void dfs(int owner, int curPrice, int visited) {
  bool &m = memo[owner][curPrice][visited];
  if (m) return;
  m = true;

  maxCnt = max(maxCnt, brianKernighan(visited));

  for (int i = 1; i < n; i++) {
    if (visited & (1 << i)) continue;
    if (price[owner][i] < curPrice) continue;
    dfs(i, price[owner][i], visited | (1 << i));
  }
}

void solve() {
  dfs(0, 0, 1);
  cout << maxCnt;
}

int main() {
  input();
  solve();
  return 0;
}
