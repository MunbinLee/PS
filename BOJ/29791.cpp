#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using pr = pair<int, int>; // 시각, 유형

enum {
  NOVA = 0,
  ORIGIN = 1
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<pr> skills;
  skills.reserve(n + m);

  map<int, int> numSkills = {
      {NOVA,   n},
      {ORIGIN, m},
  };

  for (auto &[type, cnt]: numSkills) {
    while (cnt--) {
      int skill;
      cin >> skill;
      skills.emplace_back(skill, type);
    }
  }

  sort(skills.begin(), skills.end());

  array<int, 2> cooldown{100, 360};

  array<int, 2> cooldownEnd{};
  array<int, 2> resistEnd{};
  array<int, 2> bindCnt{};

  for (auto &[time, type]: skills) {
    if (time < cooldownEnd[type]) continue;
    cooldownEnd[type] = time + cooldown[type];

    if (time < resistEnd[type]) continue;
    resistEnd[type] = time + 90;

    bindCnt[type]++;
  }

  for (int cnt: bindCnt) {
    cout << cnt << ' ';
  }

  return 0;
}
