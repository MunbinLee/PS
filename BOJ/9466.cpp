#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, team, lsIdx;
int v[100001];
int visited[100001]; // -1 NULL  0 임시 참  1 임시 거짓  2 true
int ls[100001];

void input() {
  team = 0;
  lsIdx = 0;
  cin >> n;
  memset(visited, -1, sizeof(visited));
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    if (i == v[i]) {
      visited[i] = 2;
      team++;
    }
  }
}

int solve() {
  for (int i = 1; i <= n; i++) {
    if (visited[i] != -1) continue;
    visited[i] = 0;
    ls[lsIdx++] = i;
    ls[lsIdx] = -1;
    int j = v[i];
    int cnt = 1;
    while (true) {
      if (visited[j] == 0) { // team
        team += cnt;
        for (int l = 0; l < n; l++) {
          if (ls[l] == -1) break;
          visited[ls[l]] = 2;
        }
        lsIdx = 0;
        ls[lsIdx] = -1;
        break;
      }
      if (visited[j] == 1) { // 중간에 다른 team
        for (int l = 0; l < n; l++) {
          if (ls[l] == -1) break;
          visited[ls[l]] = -1;
        }
        visited[i] = 2;
        lsIdx = 0;
        ls[lsIdx] = -1;
        break;
      }
      if (visited[j]==2) { // 불가능
        for (int l = 0; l < n; l++) {
          if (ls[l] == -1) break;
          visited[ls[l]] = 2;
        }
        lsIdx = 0;
        ls[lsIdx] = -1;
        break;
      }
      visited[j] = 1;
      ls[lsIdx++] = j;
      ls[lsIdx] = -1;
      j = v[j];
      cnt++;
    }
  }
  return n - team;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    input();
    cout << solve() << '\n';
  }
  return 0;
}
