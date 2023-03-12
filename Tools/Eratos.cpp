#include <iostream>
#include <array>

#define MAX_NUM 1000

using namespace std;

array<bool, MAX_NUM + 1> isPrime;

void eratos() {
  isPrime.fill(true);
  isPrime[1] = false;
  for (int i = 2; i * i <= MAX_NUM; i++) {
    if (!isPrime[i]) continue;
    for (int j = i * i; j <= MAX_NUM; j += i) {
      isPrime[j] = false;
    }
  }
}

int main() {
  eratos();
  return 0;
}
