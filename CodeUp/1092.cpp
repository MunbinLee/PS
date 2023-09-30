#include <iostream>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int res = 1;
  while (res % a != 0 || res % b != 0 || res % c != 0) res++;
  cout << res;
  return 0;
}
