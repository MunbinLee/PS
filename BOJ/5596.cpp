#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int sum1 = 0;
  for (int i = 0; i < 4; i++) {
    int tmp;
    cin >> tmp;
    sum1 += tmp;
  }

  int sum2 = 0;
  for (int i = 0; i < 4; i++) {
    int tmp;
    cin >> tmp;
    sum2 += tmp;
  }

  cout << max(sum1, sum2);
  return 0;
}
