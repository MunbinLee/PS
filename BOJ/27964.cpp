#include <iostream>
#include <unordered_set>

using namespace std;

const string target = "Cheese";
unordered_set<string> cheese;

bool addCheese(const string &s) {
  if (cheese.contains(s)) return false;
  if (s.size() < target.size()) return false;
  if (s.substr(s.size() - target.size()) != target) return false;

  cheese.emplace(s);
  return true;
}

bool solve() {
  int cnt = 0;
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    if (addCheese(s)) cnt++;
  }
  return cnt >= 4;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string res = solve() ? "yummy" : "sad";
  cout << res;
  return 0;
}
