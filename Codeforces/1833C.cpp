#include <iostream>
#include <algorithm>

using namespace std;

bool solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  int minOdd = INT32_MAX;
  int minEven = INT32_MAX;
  for (int &i: A) {
    cin >> i;
    if (i & 1) minOdd = min(minOdd, i);
    else minEven = min(minEven, i);
  }
  for (int mod = 0; mod <= 1; mod++) {
    bool flag = true;
    for (int i: A) {
      if ((i & 1) == mod) continue;
      if (i - minOdd > 0 && ((i - minOdd) & 1) == mod) continue;
      if (i - minEven > 0 && ((i - minEven) & 1) == mod) continue;
      flag = false;
      break;
    }
    if (flag) return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    string res = solve() ? "YES" : "NO";
    cout << res << '\n';
  }
}