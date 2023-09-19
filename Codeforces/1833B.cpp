#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pr; // value, index

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector <pr> A(n);
    vector<int> B(n), res(n);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      A[i] = {x, i};
    }
    sort(A.begin(), A.end());
    for (int &i: B) {
      cin >> i;
    }
    sort(B.begin(), B.end());
    for (int i = 0; i < n; i++) {
      int idx = A[i].second;
      res[idx] = B[i];
    }
    for (int i: res) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}