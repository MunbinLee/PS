#include <iostream>
#include <algorithm>

using namespace std;
typedef long long int ll;

int t, n, m, sa_cnt, sb_cnt;
int a[1000], b[1000];
int sa[500499], sb[500499];

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // a의 모든 부분 합
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += a[j];
      sa[sa_cnt++] = sum;
    }
  }

  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  // b의 모든 부분 합
  for (int i = 0; i < m; i++) {
    int sum = 0;
    for (int j = i; j < m; j++) {
      sum += b[j];
      sb[sb_cnt++] = sum;
    }
  }
  sort(sb, sb + sb_cnt);
}

void solve() {
  ll res = 0;
  for (int i = 0; i < sa_cnt; i++) {
    int diff = t - sa[i];
    auto ub = upper_bound(sb, sb + sb_cnt, diff); // diff 초과
    auto lb = lower_bound(sb, sb + sb_cnt, diff); // diff 이상
    res += ub - lb; // diff의 갯수만큼 더함
  }
  cout << res;
}

int main() {
  input();
  solve();
  return 0;
}
