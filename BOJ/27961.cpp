#include <iostream>
#include <cmath>

using namespace std;

typedef long long int ll;

int solve(ll n) {
  if (n <= 1) return n;
  return log2(n - 1) + 2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;
  cout << solve(n);
  return 0;
}
