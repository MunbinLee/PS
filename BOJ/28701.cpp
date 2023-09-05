#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int a = n * (n + 1) / 2;
  int b = a * a;
  int c = b;

  cout << a << '\n' << b << '\n' << c;

  return 0;
}
