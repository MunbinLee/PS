#include <iostream>
#include <vector>

using namespace std;

int n;
int nameIdx = 1;
vector<int> p;
vector<vector<int>> m;
vector<vector<int>> bracket;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  p = vector<int>(n + 1);
  m = vector<vector<int>>(n, vector<int>(n, INT32_MAX));
  bracket = vector<vector<int>>(n, vector<int>(n));
  for (int &i: p) cin >> i;
}

int solve(int i, int j) {
  if (i == j) return 0;
  if (m[i][j] != INT32_MAX) return m[i][j];
  for (int k = i; k < j; k++) {
    int tmp = solve(i, k) + solve(k + 1, j) + p[i] * p[k + 1] * p[j + 1];
    if (tmp < m[i][j]) {
      m[i][j] = tmp; // A_i, A_i+1, ..., A_j 의 최소 곱셉 횟수
      bracket[i][j] = k;
    }
  }
  return m[i][j];
}

void print(int i, int j) {
  if (i == j) {
    cout << "A" << nameIdx++;
    return;
  }
  cout << "(";
  print(i, bracket[i][j]);
  print(bracket[i][j] + 1, j);
  cout << ")";
}

void output() {
  cout << m[0][n - 1] << '\n';
  print(0, bracket[0][n - 1]);
  print(bracket[0][n - 1] + 1, n - 1);
}

int main() {
  input();
  solve(0, n - 1);
  output();
  return 0;
}
