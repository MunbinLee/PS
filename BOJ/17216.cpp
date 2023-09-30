#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int prev;
  int sum = 0;

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    if (num > sum) {
      sum = num;
      prev = num;
    } else if (num < prev) {
      sum += num;
      prev = num;
    }
  }

  cout << sum;
  return 0;
}