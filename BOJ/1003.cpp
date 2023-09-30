#include <iostream>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "ArrayIndexOutOfBounds"
#define MAX_N 40

using namespace std;

int dpZero[MAX_N + 1];
int dpOne[MAX_N + 1];

int getZero(int n) {
  if (n == 0) return 1;
  if (n == 1) return 0;
  if (dpZero[n]) return dpZero[n];
  return dpZero[n] = getZero(n - 1) + getZero(n - 2);
}

int getOne(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  if (dpOne[n]) return dpOne[n];
  return dpOne[n] = getOne(n - 1) + getOne(n - 2);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << getZero(n) << ' ' << getOne(n) << '\n';
  }
  return 0;
}

#pragma clang diagnostic pop