#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> memo;

int binomialCoefficient(int n, int k) {
  int &m = memo[n][k];
  if (m != -1) return m;

  if (!k) return 1;
  if (!n) return 0;
  return m = binomialCoefficient(n - 1, k) + binomialCoefficient(n - 1, k - 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  memo.resize(n, vector<int>(n, -1));
  cout << binomialCoefficient(n - 1, k - 1);
  return 0;
}