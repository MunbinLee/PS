#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, c;
  cin >> a >> b >> c;

  double mx = (double) a * b / c;
  double num = (double) a / b * c;
  if (num > mx) mx = num;

  cout << (long long int) mx;
  return 0;
}
