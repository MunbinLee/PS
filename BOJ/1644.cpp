#include <iostream>
#include <array>

#define MAX_NUM 4000000
#define MAX_PRIME 283146

using namespace std;
typedef long long int lld;

int n;
array<bool, MAX_NUM + 1> isPrime;
array<int, MAX_PRIME + 1> arrPrime;
array<lld, MAX_PRIME + 1> sumPrime;

void eratos() {
  isPrime.fill(true);
  isPrime[1] = false;
  for (int i = 2; i * i <= MAX_NUM; i++) {
    if (!isPrime[i]) continue;
    for (int j = i * i; j <= MAX_NUM; j += i) {
      isPrime[j] = false;
    }
  }

  int idx = 1;
  for (int i = 2; i <= MAX_NUM; i++) {
    if (isPrime[i]) arrPrime[idx++] = i;
  }

  lld sum = 0;
  for (int i = 0; i <= MAX_PRIME; i++) {
    sum += arrPrime[i];
    sumPrime[i] = sum;
  }
}

bool binarySearch(lld value) {
  int lo = 0;
  int hi = MAX_PRIME;
  while (lo <= hi) {
    int md = (lo + hi) / 2;
    lld sum = sumPrime[md];
    if (sum == value) return true;
    if (sum < value) lo = md + 1;
    else hi = md - 1;
  }
  return false;
}

int solve() {
  int cnt = 0;
  for (int i = MAX_PRIME; i >= 0; i--) {
    lld tmp = sumPrime[i];
    if (binarySearch(tmp - n)) cnt++;
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  eratos();
  cin >> n;
  cout << solve();
  return 0;
}
