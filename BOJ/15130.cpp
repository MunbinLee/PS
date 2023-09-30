#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pr; // idx, value

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> arr(10);
  vector<pr> knowns;
  for (int i = 0; i < 10; i++) {
    cin >> arr[i];
    if (arr[i]) knowns.emplace_back(i, arr[i]);
  }

  int dist = knowns[1].first - knowns[0].first;
  int diff = knowns[1].second - knowns[0].second;

  if ((int) (diff / dist) != (double) diff / dist) {
    cout << "-1";
    return 0;
  }

  int delta = diff / dist;
  int first = knowns[0].second - knowns[0].first * delta;

  for (int i = 0; i < 10; i++) {
    cout << first + delta * i << ' ';
  }

  return 0;
}
