#include <iostream>
#include <vector>

#define R 31
#define M 1234567891

using namespace std;
typedef long long int lld;

lld R_pow(int n) {
  lld res = 1;
  for (int i = 0; i < n; i++) {
    res *= R;
    res %= M;
  }
  return res;
}

lld hashing(int l, const string &s) {
  lld res = 0;
  for (int i = 0; i < l; i++) {
    res += (s[i] - 'a' + 1) * R_pow(i);
    res %= M;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int l;
  string s;
  cin >> l >> s;
  cout << hashing(l, s);
  return 0;
}
