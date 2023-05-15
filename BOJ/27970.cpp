#include <iostream>

using namespace std;

typedef long long int ll;

const int mod = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll res = 0;
  ll m = 1;

  string s;
  cin >> s;
  for (char ch: s) {
    res += m * (ch == 'O');
    res %= mod;
    m *= 2;
    m %= mod;
  }
  
  cout << res;
  return 0;
}
