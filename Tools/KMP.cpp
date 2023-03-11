#include <iostream>
#include <vector>

using namespace std;

vector<int> computeLPS(string pattern) {
  int patSize = (int) pattern.size();
  vector<int> lps(patSize);
  int j = 0;
  for (int i = 1; i < patSize; i++) {
    while (j > 0 && pattern[i] != pattern[j]) {
      j = lps[j - 1];
    }
    if (pattern[i] == pattern[j]) j++;
    lps[i] = j;
  }
  return lps;
}

void KMP(string text, string pattern) {
  vector<int> lps = computeLPS(pattern);
  int txtSize = (int) text.size();
  int patSize = (int) pattern.size();
  int j = 0;
  for (int i = 0; i < txtSize; i++) {
    while (j > 0 && text[i] != pattern[j]) {
      j = lps[j - 1];
    }
    if (text[i] == pattern[j]) j++;
    if (j == patSize) {
      cout << "Pattern found at index " << i - j + 1 << '\n';
      j = lps[j - 1];
    }
  }
}

int main() {
  string text = "abracadabra";
  string pattern = "ab";
  KMP(text, pattern);
  return 0;
}