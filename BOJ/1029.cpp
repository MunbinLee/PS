#include <iostream>
#include <vector>

using namespace std;

int n;
int maxCnt = 1;
vector<string> price; // 판매자 구매자
vector<bool> visited;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  price.resize(n);
  visited.resize(n);
  for (string &s: price) {
    cin >> s;
  }
}

void dfs(int person, int currentPrice, int cnt) {
  if (cnt == n) {
    cout << n;
    exit(0);
  }
  maxCnt = max(maxCnt, cnt);
  for (int i = 0; i < n; i++) {
    if (visited[i]) continue;
    if (price[person][i] < currentPrice) continue;
    visited[i] = true;
    dfs(i, price[person][i], cnt + 1);
    visited[i] = false;
  }
}

void solve() {
  visited[0] = true;
  for (int i = 1; i < n; i++) {
    visited[i] = true;
    dfs(i, price[0][i], 2);
    visited[i] = false;
  }
  cout << maxCnt;
}

int main() {
  input();
  solve();
  return 0;
}
