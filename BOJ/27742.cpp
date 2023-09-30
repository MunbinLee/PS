#include <iostream>
#include <array>
#include <algorithm>

using namespace std;
typedef long long int ll;

int t;
ll k;
ll w[4][4];
array<array<ll, 5>, 4> baseArr, arr; // 승점, 골득실, 다득점, 상대전적, 팀
pair<int, int> pr;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t >> k;
  t--;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> w[i][j];
      if (w[i][j] == -1) pr = {i, j};
    }
  }
}

void save() {
  for (int i = 0; i < 4; i++) {
    ll winPoints = 0;
    ll goalDiff = 0;
    ll goalSum = 0;
    ll relRank = -i;
    ll team = i;

    for (int j = 0; j < 4; j++) {
      if (i == j) continue;
      if (pr == make_pair(i, j)) continue;
      goalSum += w[i][j];
      if (pr == make_pair(j, i)) continue;

      if (w[i][j] > w[j][i]) winPoints += 3;
      else if (w[i][j] == w[j][i]) winPoints++;
      goalDiff += w[i][j] - w[j][i];
    }
    baseArr[i] = {winPoints, goalDiff, goalSum, relRank, team};
  }
}

void update() {
  arr = baseArr;
  auto [i, j] = pr;
  if (w[i][j] > w[j][i]) {
    arr[i][0] += 3;
  } else if (w[i][j] == w[j][i]) {
    arr[i][0]++;
    arr[j][0]++;
  } else {
    arr[j][0]++;
  }
  arr[i][1] += w[i][j] - w[j][i];
  arr[j][1] += w[j][i] - w[i][j];
  arr[i][2] += w[i][j];
  sort(arr.begin(), arr.end());
}

bool isQualified(ll num) {
  w[pr.first][pr.second] = num;
  update();
  if (arr[2][4] == t || arr[3][4] == t) return true;
  else return false;
}

ll binarySearch() {
  ll lo = 0;
  ll hi = k;
  ll res = -1;

  if (!isQualified(hi)) return -1;
  if (isQualified(lo)) return 0;

  while (lo <= hi) {
    ll md = (lo + hi) / 2;
    if (isQualified(md)) {
      res = md;
      hi = md - 1;
    } else {
      lo = md + 1;
    }
  }
  return res;
}

int main() {
  input();
  save();
  cout << binarySearch();
  return 0;
}
