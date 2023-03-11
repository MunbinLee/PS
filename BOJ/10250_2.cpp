#include <iostream>

using namespace std;

void solve(int h, int n) {
  int floor = (n - 1) % h + 1;
  int room = (n - 1) / h + 1;
  printf("%d%02d\n", floor, room);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int h, w, n;
    cin >> h >> w >> n;
    solve(h, n);
  }
  return 0;
}
