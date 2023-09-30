#include <iostream>

using namespace std;

long long int getSizedDecreaseNum(int size) {
  if (size == 11) return -1;
  string s;
  for (int i = 0; i < size; i++) {
    s = to_string(i).append(s);
  }
  return stoll(s);
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"

long long int getNextDecreaseNum(long long int res) {
  string s = to_string(res);
  int len = s.size();

  for (int i = len - 1; i > 0; i--) {
    if (s[i] + 1 != s[i - 1]) {
      s[i] = s[i] + 1;
      for (int j = len - 1; j > i; j--) {
        s[j] = len - j - 1 + '0';
      }
      return stoll(s);
    }
  }

  if (s[0] == '9') {
    return getSizedDecreaseNum(len + 1);
  }

  s[0] = s[0] + 1;
  for (int i = len - 1; i > 0; i--) {
    s[i] = len - i - 1 + '0';
  }
  return stoll(s);
}

#pragma clang diagnostic pop

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long int res = 0;
  int n;
  cin >> n;
  while (n--) {
    res = getNextDecreaseNum(res);
    if (res == -1) break;
  }

  cout << res;
  return 0;
}
