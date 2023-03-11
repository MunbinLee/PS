#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long int lld;

unordered_map<lld, lld> mp;

//a(0) = 0, a(2n) = a(n)+a(n-1)+n, a(2n+1) = 2a(n)+n+1
lld func(lld n) {
  if (n == 0) return 0;
  if (mp.contains(n)) return mp[n];
  if (n % 2 == 0) return mp[n] = func(n / 2) + func(n / 2 - 1) + n / 2;
  return mp[n] = 2 * func(n / 2) + n / 2 + 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  lld a, b;
  cin >> a >> b;
  cout << func(b) - func(a - 1);
  return 0;
}
