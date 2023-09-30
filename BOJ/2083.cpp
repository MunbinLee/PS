#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string name;
  int age, weight;

  while (true) {
    cin >> name >> age >> weight;
    if (age == 0) break;
    cout << name;
    if (age > 17 || weight >= 80) cout << " Senior\n";
    else cout << " Junior\n";
  }
  return 0;
}
