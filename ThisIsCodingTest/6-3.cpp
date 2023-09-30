#include <iostream>
#include <array>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  array<string, 101> names;

  int n;
  cin >> n;
  while (n--) {
    string name;
    int score;
    cin >> name >> score;
    names[score] = name;
  }

  for (string &name: names) {
    if (!name.empty()) cout << name << ' ';
  }

  return 0;
}
