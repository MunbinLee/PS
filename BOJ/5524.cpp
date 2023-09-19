#include <iostream>
#include <cstring>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;

    for (char c: s) {
      putchar(tolower(c));
    }
    printf("\n");
  }
  return 0;
}
