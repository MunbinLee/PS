#include <iostream>

using namespace std;

string color[] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};

int getValue(const string &s) {
  for (int i = 0;; i++) {
    if (s == color[i]) return i;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  int v1 = getValue(s1);
  int v2 = getValue(s2);
  int v3 = getValue(s3);

  if (v1 == 0 && v2 == 0) {
    cout << 0;
    return 0;
  }
  if (v1 == 0)cout << v2;
  else cout << v1 << v2;

  for (int i = 0; i < v3; i++) cout << '0';
  return 0;
}
