#include <iostream>
#include <unordered_set>

using namespace std;

int n, m, cnt;
string tmp;
unordered_set<string> st;

void solve() {
  cin >> n >> m;
  st.clear();
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    st.emplace(tmp);
  }

  cnt = 0;
  for (int i = 0; i < m; i++) {
    cin >> tmp;
    if (st.find(tmp) != st.end()) cnt++;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  for (int tc = 1; tc <= t; tc++) {
    solve();
    cout << '#' << tc << ' ' << cnt << '\n';
  }
  return 0;
}
