#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  while (n--) {
    string tmp;
    cin >> tmp;
    if (tmp.size() >= 6 && tmp.size() <= 9) cout << "yes\n";
    else cout << "no\n";
  }
  return 0;
}
