#include <iostream>

using namespace std;

bool solve(string s, string t) {
  int sLen = (int) s.size();
  int tLen = (int) t.size();
  int idx = 0;
  bool isFirst = true;
  while (true) {
    int sIdx = idx % sLen;
    int tIdx = idx % tLen;
    if (sIdx == 0 && tIdx == 0) {
      if (isFirst) isFirst = false;
      else return true;
    }
    if (s[sIdx] != t[tIdx]) return false;
    idx++;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    string s, t;
    cin >> s >> t;
    const char *res = solve(s, t) ? "yes" : "no";
    printf("#%d %s\n", i, res);
  }
  return 0;
}
