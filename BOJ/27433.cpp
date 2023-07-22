#include <iostream>

using namespace std;

long long factorial(int n) {
  if (n == 0) return 1;

  return factorial(n - 1) * n;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  cout << factorial(n);

  return 0;
}