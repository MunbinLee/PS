#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    unordered_set<string> st;
    int n;
    string s;
    cin >> n >> s;
    for (int i = 1; i < s.size(); i++) {
      string melody;
      melody += s[i - 1];
      melody += s[i];
      st.emplace(melody);
    }
    cout << st.size() << '\n';
  }
}