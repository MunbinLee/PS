#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  queue<int> q;
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    q.emplace(i);
  }

  cout << '<';
  while (--n) {
    for (int i = 0; i < k - 1; i++) {
      q.emplace(q.front());
      q.pop();
    }
    cout << q.front() << ", ";
    q.pop();
  }
  cout << q.front() << '>';
  return 0;
}
