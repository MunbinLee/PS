#include <iostream>
#include <vector>

using namespace std;

const int INF = 987654321;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    int minLeft = INF;
    int minRight = INF;
    int minAll = INF;
    while (n--) {
      int time;
      string bit;
      cin >> time >> bit;
      if (bit == "11") minAll = min(minAll, time);
      else if (bit == "10") minLeft = min(minLeft, time);
      else if (bit == "01") minRight = min(minRight, time);
    }
    int minTime = min(minLeft + minRight, minAll);
    if (minTime >= INF) minTime = -1;
    cout << minTime << '\n';
  }
}