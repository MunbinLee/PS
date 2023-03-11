#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> mp;

void updateFrequency(int num) {
  if (!mp.contains(num)) mp[num] = 1;
  else mp[num]++;
}

int getFrequency(int num) {
  if (!mp.contains(num)) return 0;
  return mp[num];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while (n--) {
    int num;
    cin >> num;
    updateFrequency(num);
  }

  int m;
  cin >> m;
  while (m--) {
    int num;
    cin >> num;
    cout << getFrequency(num) << ' ';
  }
  return 0;
}
