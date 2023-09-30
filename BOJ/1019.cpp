#include <iostream>

using namespace std;

int n;
int cnt[10];

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
}

void solve() {
  for (int i = 1; i <= n; i++) {
    int tmp = i;
    while (tmp) {
      cnt[tmp % 10]++;
      tmp /= 10;
    }
  }

  for (int i: cnt) cout << i << ' ';
}

int main() {
  input();
  solve();
  return 0;
}
