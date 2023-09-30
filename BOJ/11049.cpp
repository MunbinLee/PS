#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> p;
vector<vector<int>> m;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  p = vector<int>(n + 1);
  m = vector<vector<int>>(n, vector<int>(n, INT32_MAX));
  cin >> p[0];
  for (int i = 1; i < n + 1; i++) {
    int tmp;
    cin >> p[i] >> tmp;
  }
}

int solve(int i, int j) {
  if (i == j) return 0;
  if (m[i][j] != INT32_MAX) return m[i][j];
  for (int k = i; k < j; k++) {
    int tmp = solve(i, k) + solve(k + 1, j) + p[i] * p[k + 1] * p[j + 1];
    if (tmp < m[i][j]) {
      m[i][j] = tmp;
    }
  }
  return m[i][j];
}

void output() {
  cout << m[0][n - 1];
}

int main() {
  input();
  solve(0, n - 1);
  output();
  return 0;
}
