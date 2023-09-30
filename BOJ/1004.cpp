#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pr;

struct Planet {
  int cx, cy, r2;

  Planet(int cx, int cy, int r) : cx(cx), cy(cy), r2(r * r) {};

  [[nodiscard]] bool isInsidePlanet(pr pos) const {
    auto [x, y] = pos;
    int dx = cx - x;
    int dy = cy - y;
    int dist2 = dx * dx + dy * dy;
    return dist2 <= r2;
  }
};

void solve() {
  pr origin, dest;
  cin >> origin.first >> origin.second;
  cin >> dest.first >> dest.second;

  int n;
  cin >> n;

  vector<Planet *> planets(n);
  for (auto &p: planets) {
    int cx, cy, r;
    cin >> cx >> cy >> r;
    p = new Planet(cx, cy, r);
  }

  int cnt = 0;
  for (auto p: planets) {
    bool a = p->isInsidePlanet(origin);
    bool b = p->isInsidePlanet(dest);
    cnt += (a != b);
  }
  cout << cnt << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
