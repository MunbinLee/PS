#include <iostream>

#define MAX_NUM 10000

using namespace std;

int arr[MAX_NUM + 1];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while (n--) {
    int num;
    cin >> num;
    arr[num]++;
  }

  for (int i = 1; i <= MAX_NUM; i++) {
    for (int j = 0; j < arr[i]; j++) {
      cout << i << '\n';
    }
  }
  return 0;
}
