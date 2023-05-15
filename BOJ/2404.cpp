#include <iostream>

using namespace std;

int maxProd, maxCnt, res;
double target;

bool equals(double a, double b) {
  return abs(a - b) < 1e-9;
}

void solve(int cur, int prod, int cnt, double sum) {
  if (equals(sum, target)) {
    res++;
    return;
  }

  if (cur * prod > maxProd) return;
  if (cnt == maxCnt) return;
  if (sum > target) return;

  // 추가한다.
  solve(cur, prod * cur, cnt + 1, sum + 1.0 / cur);

  // 추가하지 않는다.
  solve(cur + 1, prod, cnt, sum);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int p, q;
  cin >> p >> q >> maxProd >> maxCnt;
  target = 1.0 * p / q;

  solve(1, 1, 0, 0);
  cout << res;
  return 0;
}
