#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int tc = 0; tc < 3; tc++) {
    int h, m, s;
    cin >> h >> m >> s;
    int sum = 0;
    sum += h * 60 * 60;
    sum += m * 60;
    sum += s;
    sum *= -1;

    cin >> h >> m >> s;
    sum += h * 60 * 60;
    sum += m * 60;
    sum += s;

    printf("%d %d %d\n", sum / 3600, sum % 3600 / 60, sum % 60);
  }
  return 0;
}
