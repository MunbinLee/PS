#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> v;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  v.resize(n);
  for (int &i: v) {
    cin >> i;
  }
  cin >> k;
}

void solve() {
}

int main() {
  input();
  solve();
  return 0;
}
