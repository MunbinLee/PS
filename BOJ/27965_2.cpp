#include <iostream>
#include <cmath>

using namespace std;

int n, k;

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
  long long int res = 0;
  long long int m = 1;
  for (int i = n; i >= 1; i--) {
    long long int tmp = i % k;
    tmp *= m;
    res += tmp % k;
    res %= k;
    m *= pow(10, getSize(i));
    m %= k;
  }
  cout << res;
  return 0;
}
