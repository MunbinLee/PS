#include <iostream>

using namespace std;

bool acceptable(int n, int m) {
  return n * 100 >= m;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  string res = acceptable(n, m) ? "Yes" : "No";
  cout << res;

  return 0;
}
