#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  v = vector<pair<int, int>>(n);
  for (auto &i: v) {
    int x, y;
    cin >> x >> y;
    i = {x, y};
  }
}

void solve() {
  for (auto i: v) {
    int rank = 1;
    for (auto j: v) {
      if (i.first < j.first && i.second < j.second) rank++;
    }
    cout << rank << ' ';
  }
}

int main() {
  input();
  solve();
  return 0;
}
