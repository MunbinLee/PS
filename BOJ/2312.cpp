#include <iostream>
#include <array>
#include <vector>

using namespace std;

const int MAX = 100000;
array<bool, MAX + 1> isPrime;
vector<int> primes;

void calcPrimes() {
  isPrime.fill(true);
  isPrime[1] = false;

  for (int i = 2; i * i <= MAX; i++) {
    if (!isPrime[i]) continue;
    for (int j = i * i; j <= MAX; j += i) {
      isPrime[j] = false;
    }
  }

  for (int i = 2; i <= MAX; i++) {
    if (isPrime[i]) primes.emplace_back(i);
  }
}

void factorize(int n) {
  for (int prime: primes) {
    int cnt = 0;
    while (n % prime == 0) {
      n /= prime;
      cnt++;
    }

    if (cnt) {
      cout << prime << ' ' << cnt << '\n';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  calcPrimes();

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    factorize(n);
  }

  return 0;
}
