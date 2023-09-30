#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> parent;

  int n, cur;
  cin >> n >> cur;
  parent.resize(cur + 1, -2);
  parent[cur] = -1;

  while (--n) {
    size_t x;
    cin >> x;
    parent.resize(max(parent.size(), x + 1), -2);
    if (parent[x] == -2) {
      parent[x] = cur;
    }
    cur = x;
  }

  cout << parent.size() << '\n';
  for (int i: parent) {
    cout << i << ' ';
  }

  return 0;
}
