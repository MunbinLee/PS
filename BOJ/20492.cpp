#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n;
  cin >> n;

  printf("%d %d", n * 780 / 1000, n * 956 / 1000);
  return 0;
}
