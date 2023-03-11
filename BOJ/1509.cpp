#include <iostream>
#include <vector>

using namespace std;

int n;
string s;
vector<int> res;
vector<vector<int>> dpPalindrome; // -1 정보없음 0 false 1 true

int isPalindrome(int i, int j) {
  if (i >= j) return 1;
  if (dpPalindrome[i][j] != -1) return dpPalindrome[i][j];
  if (s[i] != s[j]) return dpPalindrome[i][j] = 0;
  return dpPalindrome[i][j] = isPalindrome(i + 1, j - 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> s;
  n = (int) s.size();
  dpPalindrome.resize(n, vector<int>(n, -1));


  return 0;
}
