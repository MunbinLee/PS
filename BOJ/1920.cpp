#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  unordered_map<int, bool> mp;

  while (n--) {
    int tmp;
    cin >> tmp;
    mp[tmp] = true;
  }

  int m;
  cin >> m;

  while (m--) {
    int tmp;
    cin >> tmp;
    cout << mp[tmp] << '\n';
  }
  return 0;
}
