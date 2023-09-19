#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, b, c;
  cin >> n >> b >> c;
  vector<int> v(n);
  for (int &i: v) {
    cin >> i;
  }
  return 0;
}
