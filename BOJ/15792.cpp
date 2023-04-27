#include <iostream>
#include <iomanip>

using namespace std;
typedef long long int ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  double a, b;
  cin >> a >> b;
  cout << setprecision(1000) << a / b;
  return 0;
}
