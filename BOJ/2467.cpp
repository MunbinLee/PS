#include <iostream>

using namespace std;

int n;
int arr[100000];

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
}

void solve() {
  int minDiff = INT32_MAX;
  pair<int, int> nearests;
  int lo = 0;
  int hi = n - 1;
  while (lo != hi) {
    int sum = arr[lo] + arr[hi];
    int diff = abs(sum);
    if (diff < minDiff) {
      minDiff = diff;
      nearests = {arr[lo], arr[hi]};
    }
    if (sum < 0) lo++;
    else hi--;
  }
  cout << nearests.first << ' ' << nearests.second;
}

int main() {
  input();
  solve();
  return 0;
}
