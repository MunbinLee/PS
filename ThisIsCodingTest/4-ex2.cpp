#include <iostream>

using namespace std;

bool contains3(int num) {
  while (num) {
    if (num % 10 == 3) return true;
    num /= 10;
  }
  return false;
}

bool contains3(int h, int m, int s) {
  bool res = contains3(h) || contains3(m) || contains3(s);
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int h = 0;
  int m = 0;
  int s = 0;

  int n;
  cin >> n;

  int res = 0;
  while (h != n || m != 59 || s != 59) {
    if (contains3(h, m, s)) res++;

    s++;
    m += s / 60;
    s %= 60;
    h += m / 60;
    m %= 60;
  }

  cout << res;

  return 0;
}
