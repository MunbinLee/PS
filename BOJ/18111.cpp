#include <iostream>
#include <vector>

using namespace std;

int n, m, b;
int mnHeight = 256;
int mxHeight = 0;
vector<vector<int>> map;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> b;
  map.resize(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
      if (map[i][j] < mnHeight) mnHeight = map[i][j];
      if (map[i][j] > mxHeight) mxHeight = map[i][j];
    }
  }
}

int getTime(int height) {
  int time = 0;
  int block = b;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (map[i][j] > height) {
        int diff = map[i][j] - height;
        time += diff * 2;
        block += diff;
      } else {
        int diff = height - map[i][j];
        time += diff;
        block -= diff;
      }
    }
  }
  if (block < 0) return INT32_MAX;
  return time;
}

void solve() {
  int mnTime = INT32_MAX;
  int mnIdx = -1;
  for (int i = mxHeight; i >= mnHeight; i--) {
    int time = getTime(i);
    if (time < mnTime) {
      mnTime = time;
      mnIdx = i;
    }
  }
  cout << mnTime << ' ' << mnIdx;
}

int main() {
  input();
  solve();
  return 0;
}
