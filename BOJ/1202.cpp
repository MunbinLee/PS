#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
vector<int> bag;
vector<pair<int, int>> jewel;
priority_queue<int> pq;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;
  jewel.resize(n);
  for (auto &i: jewel) {
    cin >> i.first >> i.second;
  }
  sort(jewel.begin(), jewel.end());
  bag.resize(k);
  for (int &i: bag) {
    cin >> i;
  }
  sort(bag.begin(), bag.end());
}

long long int solve() {
  int i = 0;
  long long int sum = 0;
  for (int b: bag) {
    while (i < n && b >= jewel[i].first) {
      pq.emplace(jewel[i].second);
      i++;
    }
    if (!pq.empty()) {
      sum += pq.top();
      pq.pop();
    }
  }
  return sum;
}

int main() {
  input();
  cout << solve();
  return 0;
}
