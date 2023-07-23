#include <iostream>
#include <unordered_map>

using namespace std;
using pr = pair<int, int>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  unordered_map<string, pr> mp = {
      {"L", {0,  -1}},
      {"R", {0,  1}},
      {"U", {-1, 0}},
      {"D", {1,  0}}
  };

  int y = 1;
  int x = 1;

  int n;
  cin >> n;

  string dir;
  while (cin >> dir) {
    auto [dy, dx] = mp[dir];
    int ny = y + dy;
    int nx = x + dx;
    if (ny == 0 || ny == n + 1 || nx == 0 || nx == n + 1) continue;
    y = ny;
    x = nx;
  }

  cout << y << ' ' << x;

  return 0;
}
