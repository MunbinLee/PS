#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int cnt = 0;
    int maxCnt = 0;
    while (n--) {
      int num;
      cin >> num;
      if (num == 0) {
        cnt++;
        maxCnt = max(maxCnt, cnt);
      } else {
        cnt = 0;
      }
    }
    cout << maxCnt << '\n';
  }
}