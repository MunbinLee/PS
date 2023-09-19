#include <deque>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  deque<int> dq;
  for (int i = 1; i <= n; i++) dq.push_back(i);

  while (dq.size() != 1) {
    dq.pop_front();
    dq.push_back(dq.front());
    dq.pop_front();
  }

  cout << dq.front();
  return 0;
}
