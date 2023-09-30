#include <iostream>

using namespace std;

int lps[500000];
string txt, pat;

void input() {
  cin >> txt >> pat;
}

void computeLPS() {
  int patSize = (int) pat.size();
  int j = 0;
  lps[0] = 0;
  for (int i = 1; i < patSize; i++) {
    while (j > 0 && pat[i] != pat[j]) {
      j = lps[j - 1];
    }
    if (pat[i] == pat[j]) j++;
    lps[i] = j;
  }
}

int KMP() {
  int cnt = 0;
  computeLPS();
  int txtSize = (int) txt.size();
  int patSize = (int) pat.size();
  int j = 0;
  for (int i = 0; i < txtSize; i++) {
    while (j > 0 && txt[i] != pat[j]) {
      j = lps[j - 1];
    }
    if (txt[i] == pat[j]) j++;
    if (j == patSize) {
      cnt++;
      j = lps[j - 1];
    }
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    input();
    cout << '#' << tc << ' ' << KMP() << '\n';
  }
  return 0;
}
