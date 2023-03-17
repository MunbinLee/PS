#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>

using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
bool path[51][51][51][51];
bool visited[51][51];
queue<tuple<int, int, int>> q; // y, x, dist

void setPath(vector<vector<int>> &r) {
  for (auto i: r) {
    int x1 = i[0];
    int y1 = i[1];
    int x2 = i[2];
    int y2 = i[3];
    for (int j = x1; j < x2; j++) {
      path[y1][j][y1][j + 1] = true;
      path[y1][j + 1][y1][j] = true;
      path[y2][j][y2][j + 1] = true;
      path[y2][j + 1][y2][j] = true;
    }
    for (int j = y1; j < y2; j++) {
      path[j][x1][j + 1][x1] = true;
      path[j + 1][x1][j][x1] = true;
      path[j][x2][j + 1][x2] = true;
      path[j + 1][x2][j][x2] = true;
    }
  }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
  if (characterX == itemX && characterY == itemY) return 0;
  setPath(rectangle);
  q.emplace(characterY, characterX, 1);
  while (!q.empty()) {
    auto [y, x, dist] = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny == -1 || ny == 51 || nx == -1 || nx == 51) continue;
      if (!path[y][x][ny][nx]) continue;
      if (visited[ny][nx]) continue;
      if (ny == itemY && nx == itemX) return dist;
      visited[ny][nx] = true;
      q.emplace(ny, nx, dist + 1);
    }
  }
}

int main() {
  vector<vector<int>> r = {{1, 1, 7, 4},
                           {3, 2, 5, 5},
                           {4, 3, 6, 9},
                           {2, 6, 8, 8}};
  cout << solution(r, 1, 3, 7, 8);
  return 0;
}