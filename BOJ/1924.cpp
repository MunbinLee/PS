#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int x, y;
  cin >> x >> y;

  int dist = 0;
  dist += y - 1;

  int days[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  for (int i = 1; i < x; i++) dist += days[i];

  dist %= 7;
  string res[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
  cout << res[dist];
  return 0;
}
