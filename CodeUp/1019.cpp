#include <iostream>
#include <vector>

using namespace std;

int main() {
  string s;
  vector<int> v;

  while (getline(cin, s, '.')) {
    v.push_back(stoi(s));
  }

  cout.width(4);
  cout.fill('0');
  cout << v[0] << '.';

  cout.width(2);
  cout.fill('0');
  cout << v[1] << '.';

  cout.width(2);
  cout.fill('0');
  cout << v[2];
  return 0;
}
