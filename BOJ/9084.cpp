#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n, m;
  cin >> n;
  vector<int> coins(n);
  for (int &coin: coins) {
    cin >> coin;
  }
  cin >> m;
  vector<int> memo(m + 1);
  memo[0] = 1;

  for (int coin: coins) {
    for (int i = coin; i <= m; i++) {
      memo[i] += memo[i - coin];
    }
  }

  cout << memo[m] << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}