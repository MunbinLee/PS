#include <iostream>

using namespace std;

const int MOD = 1000000007;

int binomialCoefficient(int n, int k) {

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int m;
  cin >> m;
  while (m--) {
    int n, k;
    cin >> n >> k;
    cout << getBinomialCoefficient(n, k) << '\n';
  }
  return 0;
}