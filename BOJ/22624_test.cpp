#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <cmath>

using namespace std;

const double INF = 987654321;
const int M = 256;
int N;
vector<int> I, R, O;

void getR(int S, int A, int C) {
  R.resize(N + 1);
  R[0] = S;
  for (int i = 1; i <= N; i++) {
    R[i] = (A * R[i - 1] + C) % M;
  }
}

void getO(int S, int A, int C) {
  getR(S, A, C);
  O.resize(N + 1);
  for (int i = 1; i <= N; i++) {
    O[i] = (I[i] + R[i]) % M;
  }
}

double getH(int S, int A, int C) {
  getO(S, A, C);
  unordered_map<int, int> cnts;

  for (int i = 1; i <= N; i++) {
    cnts[O[i]]++;
  }

  double h = 0;
  for (auto [x, cnt]: cnts) {
    h -= (log(cnt) - log(N)) * cnt;
  }
  return h;
}

int solve() {
  I.resize(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> I[i];
  }


  double minH = INF;
  int resS, resA, resC;
  for (int s = 0; s <= 15; s++) {
    for (int a = 0; a <= 15; a++) {
      for (int c = 0; c <= 15; c++) {
        double h = getH(s, a, c);
        if (h < minH) {
          minH = h;
          tie(resS, resA, resC) = {s, a, c};
        }
      }
    }
  }

  cout << resS << ' ' << resA << ' ' << resC << '\n';
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  while (N) {
    solve();
    cin >> N;
  }
  return 0;
}
