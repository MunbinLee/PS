#include <iostream>

#define MIN_NUM (-10000000)
#define MAX_NUM 10000000

using namespace std;

int arr[MAX_NUM - MIN_NUM + 1];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while (n--) {
    int num;
    cin >> num;
    arr[num - MIN_NUM]++;
  }

  int m;
  cin >> m;
  while (m--) {
    int num;
    cin >> num;
    cout << arr[num - MIN_NUM] << ' ';
  }
  return 0;
}
