#include <iostream>
#include <iomanip>

using namespace std;
typedef long long int ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  const double d = 10000000000000;
  double a, b;
  cin >> a >> b;
  a *= d;
  double c = a / b;
  c /= d;
  cout << setprecision(1000) << c;
  return 0;
}
