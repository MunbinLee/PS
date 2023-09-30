#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  while (n -= 4) cout << "long ";
  cout << "long int";
  return 0;
}
