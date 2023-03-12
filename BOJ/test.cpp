#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n = 1000;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      cnt++;
    }
  }
  cout << cnt;
  return 0;
}
