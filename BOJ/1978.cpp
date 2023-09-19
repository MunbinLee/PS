#include <iostream>
#include <vector>

#define SIZE 1000

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<bool> isPrime(SIZE + 1, true);
  isPrime[1] = false;
  for (int i = 2; i * i <= SIZE; i++) {
    if (!isPrime[i]) continue;
    for (int j = i * i; j <= SIZE; j += i) {
      isPrime[j] = false;
    }
  }

  int cnt = 0;
  int n;
  cin >> n;
  while (n--) {
    int num;
    cin >> num;
    if (isPrime[num]) cnt++;
  }
  cout << cnt;
  return 0;
}
