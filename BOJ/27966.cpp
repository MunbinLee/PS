#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long int n;
  cin >> n;
  cout << (n - 1) * (n - 1) << '\n';
  for (int i = 2; i <= n; i++) {
    cout << 1 << ' ' << i << '\n';
  }
  return 0;
}
