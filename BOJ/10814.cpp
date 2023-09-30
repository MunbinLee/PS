#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct member {
  int age{};
  string name;

  bool operator<(const member &other) const {
    return age < other.age;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<member> v(n);
  for (auto &i: v) {
    cin >> i.age >> i.name;
  }
  stable_sort(v.begin(), v.end());

  for (const auto &i: v) {
    cout << i.age << ' ' << i.name << '\n';
  }
  return 0;
}
