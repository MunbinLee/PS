// 13개 오답

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n, k, cnt;
long long int ship, sum;
vector<int> popul;

void solve() {
  for (int i : popul) {
    if (i > ship) break;
    cnt++;
    ship += i;
    sum -= i;
    if (ship >= sum) return;
  }
  cnt = -1;
}

int main() {
  scanf("%d", &t);

  for (int i = 1; i <= t; i++) {
    scanf("%d %d", &n, &k);
    popul = vector<int>(n);
    ship = k;
    cnt = 0;
    sum = 0;

    for (int j = 0; j < n; j++) {
      scanf("%d", &popul[j]);
      sum += popul[j];
    }
    sort(popul.begin(), popul.end());

    solve();

    printf("#%d %d\n", i, cnt);
  }
  return 0;
}
