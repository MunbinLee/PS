#include <iostream>

using namespace std;

int n;
string s;

int calc(int a, int b, char ch) {
  if (ch == '+') return a + b;
  if (ch == '-') return a - b;
  if (ch == '*') return a * b;
}

int getMaxValue(int idx, int a) {
  if (idx == n) return a;

  char op = s[idx];
  int b = s[idx + 1] - '0';

  // (a+b)+c...
  int maxValue = getMaxValue(idx + 2, calc(a, b, op));
  if (idx == n - 2) return maxValue;

  // a+(b+c)...
  char op2 = s[idx + 2];
  int c = s[idx + 3] - '0';
  maxValue = max(maxValue,
                 getMaxValue(idx + 4, calc(a, calc(b, c, op2), op)));
  return maxValue;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> s;
  int a = s[0] - '0';
  cout << getMaxValue(1, a);
  return 0;
}
