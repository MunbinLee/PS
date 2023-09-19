#include <cstdio>
#include <cstring>

#define MAX 41
#define max(a, b)  (((a) > (b)) ? (a) : (b))

char A[MAX], B[MAX];
int dp[MAX][MAX];

int main() {
  scanf("%s %s", A, B);
  int m = strlen(A), n = strlen(B);
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (A[i - 1] == B[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  int len = dp[m][n];
  char lcs[MAX];
  int i = m, j = n, k = 0;
  while (len > 0) {
    if (A[i - 1] == B[j - 1]) {
      lcs[k++] = A[i - 1];
      i--;
      j--;
      len--;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
      i--;
    } else {
      j--;
    }
  }
  for (int i = k - 1; i >= 0; i--) {
    printf("%c", lcs[i]);
  }
  return 0;
}