#include <iostream>
#include <set>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b;
  cin >> a >> b;
  set<int> A, B;

  for (int i = 0; i < a; i++) {
    int n;
    cin >> n;
    A.emplace(n);
  }

  for (int i = 0; i < b; i++) {
    int n;
    cin >> n;
    B.emplace(n);
  }

  auto it = B.begin();
  while (it != B.end()) {
    auto cur = it++;
    if (A.contains(*cur)) {
      A.erase(*cur);
      B.erase(cur);
    }
  }

  int res = A.size() + B.size();
  cout << res;
  return 0;
}