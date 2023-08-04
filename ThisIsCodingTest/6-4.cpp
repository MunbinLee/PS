#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> A(n);
  for (int &i: A) {
    cin >> i;
  }
  sort(A.begin(), A.end());

  vector<int> B(n);
  for (int &i: B) {
    cin >> i;
  }
  sort(B.begin(), B.end(), greater<>());

  for (int i = 0; i < k; i++) {
    if (A[i] >= B[i]) break;
    swap(A[i], B[i]);
  }

  int sum = 0;
  for (int i: A) {
    sum += i;
  }
  cout << sum;

  return 0;
}