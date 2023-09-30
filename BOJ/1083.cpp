#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  list<int> ls;
  vector<int> v(n);
  for (int &i: v) {
    cin >> i;
    ls.push_back(i);
  }
  sort(v.begin(), v.end(), greater<>());
  int s;
  cin >> s;

  int idx = 0;
  while (true) {
    if (s == 0 || idx >= n) break;

    auto lsFront = ls.begin();
    advance(lsFront, idx);
    for (int i: v) {
      if (i <= *lsFront) break;

      auto mx = find(ls.begin(), ls.end(), i);
      int mxIdx = (int) distance(ls.begin(), mx);
      int dist = mxIdx - idx;
      if (dist <= 0 || s < dist) continue;

      s -= dist;
      auto source = mx;
      ls.splice(lsFront, ls, source);
      break;
    }
    idx++;
  }

  for (int i: ls) cout << i << ' ';
  return 0;
}
