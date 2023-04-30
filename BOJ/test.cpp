#include <iostream>

using namespace std;

int bitCount(int visited) {
  return __builtin_popcount(visited);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int a = 1<<2;
  cout << a;
  return 0;
}
