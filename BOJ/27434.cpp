#include <iostream>

using namespace std;

long long memo[100001] = {1};

long long factorial(int n) {
  long long &m = memo[n];
  if (m) return m;

  return m = factorial(n - 1) * n;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  cout << factorial(n);

  return 0;
}