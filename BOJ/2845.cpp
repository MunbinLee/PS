#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int num = 1;
  for (int i = 0; i < 2; i++) {
    int tmp;
    cin >> tmp;
    num *= tmp;
  }

  for (int i = 0; i < 5; i++) {
    int tmp;
    cin >> tmp;
    cout << tmp - num << ' ';
  }
  return 0;
}
