#include <iostream>

using namespace std;

int n, s;
int arr[100000]; // 누적 합

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tmp;
  int sum = 0;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    sum += tmp;
    arr[i] = sum;
  }
}

int upperBound(int lo, int hi, int value) {
  while (lo < hi) {
    int md = (lo + hi) / 2;
    if (arr[md] <= value) lo = md + 1;
    else hi = md;
  }
  return lo;
}

void solve() {
  int minLen = INT32_MAX;
  for (int i = 0; i < n; i++) {
    int diff = arr[i] - s;
    if (diff < 0) continue;
    int j = upperBound(0, i, diff) - 1;
    int len = i - j;
    if (len < minLen) minLen = len;
  }

  if (minLen == INT32_MAX) minLen = 0;
  cout << minLen;
}

int main() {
  input();
  solve();
  return 0;
}
