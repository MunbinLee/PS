#include <iostream>
#include <unordered_map>

#define div 1000000007

using namespace std;
typedef long long int ll;

int m;
unordered_map<size_t, ll> dp;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> m;
}

size_t key(int i, int j) {
  return (size_t) i << 32 | (unsigned int) j;
}

ll query(int n, int k) {
  if (k > n - k) k = n - k;
  if (k == 0) return 1;
  if (dp.contains(key(n, k))) return dp[key(n, k)];
  return dp[key(n, k)] = (query(n - 1, k - 1) + query(n - 1, k)) % div;
}

void input() {
  while (m--) {
    int n, k;
    cin >> n >> k;
    cout << query(n, k) << '\n';
  }
}

int main() {
  input();
  solve();
  return 0;
}
