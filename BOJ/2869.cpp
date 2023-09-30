#include <iostream>
#include <cmath>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, v;
  cin >> a >> b >> v;
  cout << (int) ceil((double) (v - a) / (a - b)) + 1;
  return 0;
}
