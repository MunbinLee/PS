#include <iostream>
#include <vector>

using namespace std;

int getGCD(int a, int b) {
  if (!b) return a;
  return getGCD(b, a % b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> v(n);
  vector<int> prefGCD(n); // prefGCD[i] = [0, i) gcd
  vector<int> suffGCD(n + 1); // suffGCD[i] = [i, n) gcd

  for (int &i: v) {
    cin >> i;
  }

  int pref = v[0];
  for (int i = 1; i < n; i++) {
    pref = getGCD(pref, v[i - 1]);
    prefGCD[i] = pref;
  }

  int suff = v[n - 1];
  for (int i = n - 1; i >= 0; i--) {
    suff = getGCD(suff, v[i]);
    suffGCD[i] = suff;
  }

  int maxGCD = -1;
  int maxK;
  for (int i = 0; i < n; i++) {
    int k = v[i];
    int gcd = getGCD(prefGCD[i], suffGCD[i + 1]);
    if (k % gcd == 0) continue;
    if (gcd > maxGCD) {
      maxGCD = gcd;
      maxK = k;
    }
  }

  cout << maxGCD;
  if (maxGCD != -1) cout << ' ' << maxK;

  return 0;
}