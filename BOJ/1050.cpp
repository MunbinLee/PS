#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;
using Recipe = vector<pair<string, int>>;

const double MAX = 1000000001;
const double INF = 10987654321;

unordered_map<string, int> baseCosts;
unordered_map<string, double> costs;
unordered_map<string, vector<Recipe>> recipes;
unordered_map<string, bool> visited;

double getCost(const string &s) {
  if (costs.contains(s)) {
    visited[s] = false;
    return costs[s];
  }

  double minCost = INF;
  if (baseCosts[s]) minCost = baseCosts[s];

  if (visited[s]) return minCost;
  visited[s] = true;

  for (auto &recipe: recipes[s]) {
    double cost = 0;
    for (auto &[name, cnt]: recipe) {
      if (getCost(name) == INF) {
        cost = INF;
        break;
      }
      cost += getCost(name) * cnt;
      cost = min(cost, MAX);
    }
    minCost = min(minCost, cost);
  }

  visited[s] = false;

  return costs[s] = minCost;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  while (n--) {
    string ingredient;
    int cost;
    cin >> ingredient >> cost;
    baseCosts[ingredient] = cost;
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
      recipe.emplace_back(ingredient, cnt);
    }
    recipes[name].emplace_back(recipe);
  }

  double cost = getCost("LOVE");
  cout << (cost == INF ? -1 : cost);
  return 0;
}