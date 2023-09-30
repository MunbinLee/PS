#include <iostream>

using namespace std;

int pow(int b, int e) {
  int res = 1;
  while (e--) {
    res *= b;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int maxN[] = {0, 1, 21, 321, 4321, 54321, 654321, 7654321, 87654321, 987654321};
  for (int &i: maxN) {
    i *= 9;
  }

  int n;
  cin >> n;

  int len = 1;
  while (maxN[len] < n) {
    len++;
  }

  int dist = n - maxN[len - 1] - 1;
  int num = pow(10, len - 1) + dist / len;
  int idx = dist % len;
  string s = to_string(num);
  cout << s[idx];
  return 0;
}
