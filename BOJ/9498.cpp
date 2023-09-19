#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  char c;
  if (n >= 90) c = 'A';
  else if (n >= 80) c = 'B';
  else if (n >= 70) c = 'C';
  else if (n >= 60) c = 'D';
  else c = 'F';

  cout << c;
  return 0;
}
