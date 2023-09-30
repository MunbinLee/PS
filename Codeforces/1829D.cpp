#include <iostream>

using namespace std;

bool canMakePile(int n, const int m) {
  if (n == m) return true;
  if (n % 3 == 0) {
    if (canMakePile(n / 3 * 2, m)) return true;
    if (canMakePile(n / 3, m)) return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    string res = canMakePile(n, m) ? "YES" : "NO";
    cout << res << '\n';
  }
}