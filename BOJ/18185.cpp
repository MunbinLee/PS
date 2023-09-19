#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  v = vector<int>(n + 2);
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    v[i] = num;
  }

  int res = 0;
  for (int i = 0; i < n; i++) {
    if (v[i + 1] > v[i + 2]) {
      int cnt = min(v[i], v[i + 1] - v[i + 2]);
      v[i] -= cnt;
      v[i + 1] -= cnt;
      res += cnt * 5;
    }

    int cnt2 = min(v[i], min(v[i + 1], v[i + 2]));
    v[i] -= cnt2;
    v[i + 1] -= cnt2;
    v[i + 2] -= cnt2;
    res += cnt2 * 7;

    if (v[i + 1] == 0) {
      res += v[i] * 3;
      i++;
    } else if (v[i + 2] == 0) {
      int cnt = min(v[i], v[i + 1]);
      res += (v[i] + v[i + 1]) * 3 - cnt;
      i += 2;
    }
  }
  cout << res;
  return 0;
}
