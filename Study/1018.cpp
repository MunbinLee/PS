#include <iostream>
#include <vector>

using namespace std;

int len1, len2;
string s1, s2;
vector<vector<int>> dp;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> s1 >> s2;
  len1 = (int) s1.size();
  len2 = (int) s2.size();
  dp = vector<vector<int>>(len1 + 1, vector<int>(len2 + 1, -1));
}

int LCS(int i, int j) {
  if (i == 0 || j == 0) return 0;
  if (s1[i - 1] == s2[j - 1]) return dp[i][j] = LCS(i - 1, j - 1) + 1;
  if (dp[i][j] != -1) return dp[i][j];
  return dp[i][j] = max(LCS(i, j - 1), LCS(i - 1, j));
}

void printLCS() {
  int index = dp[len1][len2];
  char lcs[index + 1];
  lcs[index] = '\0';
  int i = len1;
  int j = len2;
  while (i && j) {
    if (s1[i - 1] == s2[j - 1]) {
      lcs[index - 1] = s1[i - 1];
      i--;
      j--;
      index--;
      continue;
    }
    if (dp[i - 1][j] > dp[i][j - 1]) i--;
    else j--;
  }
  cout << lcs;
}

int main() {
  input();
  cout << LCS(len1, len2) << '\n';
  printLCS();
  return 0;
}
