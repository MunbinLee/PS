#include <iostream>
#include <algorithm>

using namespace std;

int l, c;
vector<char> v;

bool isVowel(char ch) {
  return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

bool isCorrect(const string &s) {
  int vowel = 0;
  int noun = 0;
  for (char ch: s) {
    isVowel(ch) ? vowel++ : noun++;
  }

  return (vowel >= 1 && noun >= 2);
}

void dfs(int idx, int len, const string &s) {
  if (len == l) {
    if (!isCorrect(s)) return;
    cout << s << '\n';
    return;
  }
  if (idx == c) return;

  dfs(idx + 1, len + 1, s + v[idx]);
  dfs(idx + 1, len, s);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> l >> c;
  v.resize(c);
  for (char &ch: v) {
    cin >> ch;
  }
  sort(v.begin(), v.end());

  dfs(0, 0, "");
  return 0;
}
