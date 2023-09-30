#include <iostream>
#include <algorithm>

using namespace std;

struct Pos {
  int x, y;

  bool operator<(const Pos &other) const {
    if (y == other.y) return x < other.x;
    return y < other.y;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector <Pos> v(n);
  for (auto &i: v) {
    cin >> i.x >> i.y;
  }
  sort(v.begin(), v.end());

  for (auto i: v) {
    cout << i.x << ' ' << i.y << '\n';
  }
  return 0;
}
