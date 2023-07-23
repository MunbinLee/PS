#include <iostream>
#include <vector>

using namespace std;
using pr = pair<int, int>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<pr> dPos = {
      {-2, -1},
      {-2, 1},
      {-1, -2},
      {-1, 2},
      {1, -2},
      {1, 2},
      {2, -1},
      {2, 1},
  };

  string s;
  cin >> s;

  int y = s[1] - '0';
  int x = s[0] - 'a' + 1;

  int res = 0;
  for (auto [dy, dx]: dPos) {
    int ny = y + dy;
    int nx = x + dx;
    if (ny < 1 || ny > 8 || nx < 1 || nx > 8) continue;
    res++;
  }

  cout << res;

  return 0;
}
