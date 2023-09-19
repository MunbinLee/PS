#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pr = pair<long long, int>; // 체력, 보상

int n, m, k;
vector<long long> damages;
vector<pr> bosses;

long long int getBossTime(long long hp, long long damage) {
  if (hp <= damage) return 1;
  if (hp % damage == 0) return hp / damage;
  return hp / damage + 1;
}

int getMaxRewardSum(int idx, int time, int rewardSum, const long long damage) {
  if (idx == k) return rewardSum;

  int res = getMaxRewardSum(idx + 1, time, rewardSum, damage);
  long long dtime = getBossTime(bosses[idx].first, damage);
  if (time + dtime <= 15 * 60) {
    res = max(res, getMaxRewardSum(idx + 1, time + dtime, rewardSum + bosses[idx].second, damage));
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> k;

  damages.resize(n);
  for (auto &damage: damages) {
    cin >> damage;
  }
  sort(damages.begin(), damages.end(), greater<>());
  damages.resize(m);

  bosses.resize(k);
  for (auto &[health, reward]: bosses) {
    cin >> health >> reward;
  }

  int res = 0;
  for (auto damage: damages) {
    res += getMaxRewardSum(0, 0, 0, damage);
  }
  cout << res;

  return 0;
}
