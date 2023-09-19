#include <iostream>
#include <vector>

using namespace std;

int arr[1000001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i: v) {
    cin >> i;
    arr[i]++;
  }

  for (int i: v) {
    int cnt = -1;
    for (int j = 1; j * j <= i; j++) {
      if (i % j == 0) {
        cnt += arr[j];
        if (j * j != i) cnt += arr[i / j];
      }
    }
    cout << cnt << '\n';
  }
  return 0;
}
