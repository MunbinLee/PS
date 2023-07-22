#include <iostream>

using namespace std;

bool contains(int x) {
  string s = to_string(x);
  return s.find("50") != string::npos;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int cnt = n;
  for (int i = 1; i < n; i++) {
    if (contains(i)) cnt++;
  }

  cout << cnt;
  return 0;
}