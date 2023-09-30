#include <iostream>

using namespace std;

int arr1[6];
int arr2[6];

void input() {
  for (int i = 0; i < 6; i++) {
    scanf("%d", &arr1[i]);
    scanf("%d", &arr2[i]);
  }
}

void swap(int &n1, int &n2) {
  int tmp = n1;
  n1 = n2;
  n2 = tmp;
}

void sort(int &n1, int &n2, int &n3) {
  if (n1 > n3) swap(n1, n3);
  if (n1 > n2) swap(n1, n2);
  if (n2 > n3) swap(n2, n3);
}

bool isBabyGin(int n1, int n2, int n3) {
  sort(n1, n2, n3);
  if (n1 + 1 == n2 && n2 + 1 == n3) return true; // run
  if (n1 == n2 == n3) return true; // triplet
  return false;
}

int whenBabyGin(int player) {
  int *pArr;
  if (player == 1) pArr = arr1;
  else pArr = arr2;

  for (int i = 2; i < 6; i++) {
    for (int j = 0; j <= i; j++) {
      for (int k = j + 1; k <= i; k++) {
        for (int l = k + 1; l <= i; l++) {
          if (isBabyGin(pArr[j], pArr[k], pArr[l])) {
            return i;
          }
        }
      }
    }
  }
  return INT32_MAX;
}

int solve() {
  int cnt1 = whenBabyGin(1);
  int cnt2 = whenBabyGin(2);
  if (cnt1 == cnt2) return 0;
  if (cnt1 < cnt2) return 1;
  return 2;
}

int main() {
  int t;
  scanf("%d", &t);

  for (int tc = 1; tc <= t; tc++) {
    input();
    printf("#%d %d\n", tc, solve());
  }
  return 0;
}
