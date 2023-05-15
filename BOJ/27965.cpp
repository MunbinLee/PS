#include <iostream>
#include <unordered_map>

using namespace std;

int n, k;
unordered_map<int, int> memo;

int pow(int m) {
  if (memo.contains(m)) return memo[m];
  int a = m / 2;
  int b = m - a;
  return memo[m] = (pow(a) % k * pow(b) % k) % k;
}

int getSize(int i) {
  int res = 0;
  while (i) {
    res++;
    i /= 10;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;

  memo[0] = 0;
  memo[1] = 10 % k;
  long long int res = 0;
  for (int i = 1; i <= n; i++) {
    res *= pow(getSize(i));
    res %= k;
    res += i;
    res %= k;
  }
  cout << res;
  return 0;
}
