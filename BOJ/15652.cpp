#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  while (true) {
    for (int i = 0; i < m; i++) {
      for (int j = 1; j <= n; j++) {
        cout << j << ' ';
      }
    }
  }
  return 0;
}
