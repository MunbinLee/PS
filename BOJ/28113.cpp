#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, a, b;
  cin >> n >> a >> b;

  string res;
  if (a == b) res = "Anything";
  else if (a > b) res = "Subway";
  else res = "Bus";
  cout << res;
  
  return 0;
}