#include <iostream>
#include <cmath>

using namespace std;

void hanoi(int begin, int end, int n) {
  if (n == 1) {
    cout << begin << ' ' << end << '\n';
    return;
  }
  int mid = 6 - begin - end;
  hanoi(begin, mid, n - 1);
  hanoi(begin, end, 1);
  hanoi(mid, end, n - 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  string s = to_string(pow(2, n));
  s = s.substr(0, s.find('.'));
  int idx = s.size() - 1;
  s[idx] -= 1;
  cout << s << '\n';
  if (n <= 20) hanoi(1, 3, n);
  return 0;
}
