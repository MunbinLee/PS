#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> v;

void input() {
  cin >> n >> k;
  v.resize(n);
  for (int &i: v) cin >> i;
  sort(v.begin(), v.end());
}

void solve() {
  int numStone = 0;
  int sumExp = 0;
  for (int i = 0; i < n; i++) {
    sumExp += v[i] * numStone;
    numStone = min(numStone + 1, k);
  }
  cout << sumExp;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  input();
  solve();
  return 0;
}
