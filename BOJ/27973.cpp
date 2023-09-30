#include <iostream>

using namespace std;

typedef long long int ll;

int q;
ll a = 1;
ll b = 0;
ll idx = 1;

void execute(int cmd) {
  ll x;
  switch (cmd) {
    case 0:
      cin >> x;
      b += x;
      break;
    case 1:
      cin >> x;
      a *= x;
      b *= x;
      break;
    case 2:
      cin >> x;
      idx += x;
      break;
    default:
      ll res = idx * a + b;
      cout << res << '\n';
      break;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> q;
  while (q--) {
    int cmd;
    cin >> cmd;
    execute(cmd);
  }
  return 0;
}
