#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int R, C;

pair<int, int> getStartPos(const vector<string> &park) {
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (park[i][j] == 'S') return {i, j};
    }
  }
  return {-1, -1};
}

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

pair<int, int> moveDog(int r, int c, int dir, int dist, const vector<string> &park) {
  int tmp_r = r;
  int tmp_c = c;
  while (dist--) {
    r += dr[dir];
    c += dc[dir];
    if (r == -1 || r == R || c == -1 || c == C || park[r][c] == 'X') return {tmp_r, tmp_c};
  }
  return {r, c};
}

vector<int> solution(vector<string> &park, const vector<string> &routes) {
  unordered_map<char, int> mp;
  mp['N'] = 0;
  mp['S'] = 1;
  mp['W'] = 2;
  mp['E'] = 3;
  R = park.size();
  C = park[0].size();
  pair<int, int> s = getStartPos(park);
  int r = s.first;
  int c = s.second;
  park[r][c] = 'O';

  for (const string &route: routes) {
    int dir = mp[route[0]];
    int dist = route[2] - '0';
    pair<int, int> pos = moveDog(r, c, dir, dist, park);
    r = pos.first;
    c = pos.second;
  }

  return {r, c};
}

int main() {

  vector<string> park = {"SOO", "OOO", "OOO"};
  vector<string> routes = {"E 2", "S 2", "W 1"};
  auto a = solution(park, routes);
  cout << a[0] << ' ' << a[1];
  return 0;
}
