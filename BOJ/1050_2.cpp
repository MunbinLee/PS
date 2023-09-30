#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;
using Recipe = vector<pair<long long, string>>;

const long long MAX = 1000000001;
const long long INF = 10987654321;

unordered_map<string, long long> costs;
vector<pair<string, Recipe>> recipes;

void input() {
  int n, m;
  cin >> n >> m;

  while (n--) {
    string ingredient;
    int cost;
    cin >> ingredient >> cost;
    costs[ingredient] = cost;
  }

  while (m--) {
    string name, formula, token;
    cin.ignore();
    getline(cin, name, '=');
    cin >> formula;
    stringstream ss(formula);
    Recipe recipe;
    while (getline(ss, token, '+')) {
      int cnt = token[0] - '0';
      string ingredient = token.substr(1);
      recipe.emplace_back(cnt, ingredient);
    }
    recipes.emplace_back(name, recipe);
  }
}

void solve() {
  bool loop = true;
  while (loop) {
    loop = false;
    for (auto &[name, recipe]: recipes) {
      long long cost = 0;
      for (auto &[cnt, ingredient]: recipe) {
        if (!costs.contains(ingredient)) {
          cost = INF;
          break;
        }
        cost += costs[ingredient] * cnt;
        cost = min(cost, MAX);
      }

      if (cost == INF || costs.contains(name) && cost >= costs[name]) continue;
      costs[name] = cost;
      loop = true;
    }
  }

  if (!costs.contains("LOVE")) costs["LOVE"] = -1;
  cout << costs["LOVE"];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  input();
  solve();
  return 0;
}