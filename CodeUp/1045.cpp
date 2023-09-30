#include <iostream>

using namespace std;

int main() {
  float a, b;
  cin >> a >> b;

  cout << a + b << '\n';
  cout << a - b << '\n';
  cout << a * b << '\n';
  cout << (int) (a / b) << '\n';
  cout << (int) a % (int) b << '\n';
  printf("%.2f", a / b);
  return 0;
}
