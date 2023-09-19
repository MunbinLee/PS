#include <iostream>

using namespace std;

int n, u, l;

string solve() {
  if (n >= 1000 && (u >= 8000 || l >= 260)) return "Very Good";
  if (n >= 1000) return "Good";
  return "Bad";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> u >> l;

  cout << solve();

  return 0;
}
