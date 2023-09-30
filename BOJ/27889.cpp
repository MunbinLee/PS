#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  unordered_map<string, string> mp = {
      {"NLCS", "North London Collegiate School"},
      {"BHA",  "Branksome Hall Asia"},
      {"KIS",  "Korea International School"},
      {"SJA",  "St. Johnsbury Academy"}
  };

  string s;
  cin >> s;

  cout << mp[s];

  return 0;
}