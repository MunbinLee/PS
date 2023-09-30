#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int sum = 0;
  for (int i = 0; i < 4; i++) {
    int tmp;
    cin >> tmp;
    sum += tmp;
  }

  cout << sum / 60 << '\n' << sum % 60;
  return 0;
}
