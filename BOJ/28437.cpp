#include <iostream>
#include <array>
#include <list>

using namespace std;

array<int, 100001> isPrime, memo;
array<bool, 100001> exists;
list<int> primeList;

void eratos() {
  isPrime.fill(true);
  isPrime[1] = false;

  for (int i = 2; i * i <= 100000; i++) {
    if (!isPrime[i]) continue;
    for (int j = i * i; j <= 100000; j += i) {
      isPrime[j] = false;
    }
  }

  for (int i = 2; i <= 100000; i++) {
    if (isPrime[i]) primeList.emplace_back(i);
  }
}

int dp(int n) {
  int &m = memo[n];
  if (m != -1) return m;

  m = 0;
  if (exists[n]) m++;
  if (isPrime[n]) return ++m;

  return m;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  memo.fill(-1);
  eratos();

  int n;
  cin >> n;
  while (n--) {
    int num;
    cin >> num;
    exists[num] = true;
  }

  for (int i = 1; i <= 100000; i++) {
    dp(i);
  }

  int q;
  cin >> q;
  while (q--) {
    int num;
    cin >> num;
    cout << memo[num] << ' ';
  }

  return 0;
}
