#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

void init(int size) {
  parent.resize(size + 1);
  for (int i = 1; i <= size; i++) {
    parent[i] = i;
  }
}

int find(int x) {
  if (x == -1) return -1;
  if (parent[x] == x) return x;

  return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
  a = find(a);
  b = find(b);
  parent[a] = b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, numTruthPeople;
  cin >> n >> m >> numTruthPeople;

  init(n);

  int truthPerson = -1;
  if (numTruthPeople) {
    vector<int> truthPeople(numTruthPeople);
    for (int &i: truthPeople) {
      cin >> i;
    }
    for (int i: truthPeople) {
      merge(i, truthPeople[0]);
    }
    truthPerson = find(truthPeople[0]);
  }

  vector<vector<int>> party(m);
  for (auto &v: party) {
    int numPeople;
    cin >> numPeople;
    v.resize(numPeople);
    for (int &i: v) {
      cin >> i;
    }
    for (int i: v) {
      merge(i, v[0]);
    }
  }

  int cnt = 0;
  for (auto &v: party) {
    if (find(v[0]) != find(truthPerson)) cnt++;
  }

  cout << cnt;
  return 0;
}