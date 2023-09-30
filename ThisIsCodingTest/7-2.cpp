#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  unordered_map<int, bool> exists;

  int n;
  cin >> n;
  while (n--) {
    int num;
    cin >> num;
    exists[num] = true;
  }

  int m;
  cin >> m;
  while (m--) {
    int num;
    cin >> num;
    string res = exists[num] ? "yes" : "no";
    cout << res << ' ';
  }

  return 0;
}