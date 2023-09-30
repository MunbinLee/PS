#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int q = -1;
  unordered_map<string, bool> visited;

  int n;
  cin >> n;
  vector<string> v(n);
  for (int i = 0; i < n; i++) {
    string &s = v[i];
    cin >> s;
    visited[s] = true;
    if (s == "?") {
      q = i;
    }
  }

  int m;
  cin >> m;
  while (m--) {
    string s;
    cin >> s;
    if (visited[s]) continue;
    if (q != 0 && v[q - 1].back() != s.front()) continue;
    if (q != n - 1 && s.back() != v[q + 1].front()) continue;
    cout << s;
    break;
  }

  return 0;
}
