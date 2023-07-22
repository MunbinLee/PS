#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
  if (a < 0 && b < 0) return a > b;
  return a < b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, s;
  cin >> n >> s;
  vector<int> v(n);
  for (int &i: v) {
    cin >> i;
  }
  sort(v.begin(), v.end(), cmp);

  int sum = 0;
  for (int &i: v) {
    sum += i;
    i = sum;
  }

  return 0;
}