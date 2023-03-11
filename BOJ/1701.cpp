#include <iostream>

using namespace std;

int txtSize;
int lps[5000];
string txt;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> txt;
  txtSize = (int) txt.size();
}

int getMaxLPS(int start) {
  int mx = 0;
  int j = 0;
  lps[0] = 0;
  for (int i = 1; i < txtSize - start; i++) {
    while (j > 0 && txt[i + start] != txt[j + start]) {
      j = lps[j - 1];
    }
    if (txt[i + start] == txt[j + start]) {
      j++;
      if (j > mx) mx = j;
    }
    lps[i] = j;
  }
  return mx;
}

int solve() {
  int mx = 0;
  for (int i = 0; i < txtSize - 1; i++) {
    int tmp = getMaxLPS(i);
    if (tmp > mx) mx = tmp;
  }
  return mx;
}

int main() {
  input();
  cout << solve();
  return 0;
}
