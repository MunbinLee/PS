#include <iostream>\


using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int sum = 0;
  int m = 0;

  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    sum += tmp;
    m = max(m, tmp);
  }

  cout << (double) sum / m * 100 / n;
  return 0;
}
