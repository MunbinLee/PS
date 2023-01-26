#include <iostream>

using namespace std;

bool isAlive(const int n, int div) {
  if (n % div == 0) return false;
  if (n < div) return true;
  return isAlive(n - n / div, div + 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  cout << (isAlive(n, 2) ? "Yes" : "No");
  return 0;
}
