#include <iostream>

using namespace std;

const int INF = 987654321;
int q = -1;
int inst[100000];
int memo[100000][5][5]; // 단계, 왼발, 오른발

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  do {
    cin >> inst[++q];
  } while (inst[q]);
}

// s를 e로 움직이는 데 필요한 비용
int getCost(int s, int e) {
  if (s == e) return 1;
  if (s == 0) return 2;
  if (abs(e - s) == 2) return 4;
  return 3;
}

int dp(int i, int left, int right) {
  if (i == q) return 0;
  if (i && left == right) return INF;

  int &m = memo[i][left][right];
  if (m) return m;
  return m = min(dp(i + 1, inst[i], right) + getCost(left, inst[i]),
                 dp(i + 1, left, inst[i]) + getCost(right, inst[i]));
}

int main() {
  input();
  cout << dp(0, 0, 0);
  return 0;
}
