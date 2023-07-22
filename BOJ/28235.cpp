#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  unordered_map<string, string> mp = {
      {"SONGDO", "HIGHSCHOOL"},
      {"CODE", "MASTER"},
      {"2023", "0611"},
      {"ALGORITHM", "CONTEST"}
  };

  string s;
  cin >> s;

  cout << mp[s];

  return 0;
}