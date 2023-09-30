#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<bool>> path;
vector<bool> visited;
vector<int> res;
int n;

void DFS(int v) {
  visited[v] = true;
  res.push_back(v);
  for (int i = 1; i <= n; i++) {
    if (visited[i]) continue;
    if (!path[v][i]) continue;
    DFS(i);
  }
}

void BFS(int v) {
  visited[v] = true;
  queue<int> q;
  q.push(v);

  while (!q.empty()) {
    int i = q.front();
    cout << i << ' ';
    q.pop();
    for (int j = 1; j <= n; j++) {
      if (visited[j]) continue;
      if (!path[i][j]) continue;
      visited[j] = true;
      q.push(j);
    }
  }
}

void print() {
  for (int i: res) {
    cout << i << ' ';
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int m, v;
  cin >> n >> m >> v;

  path = vector(n + 1, vector<bool>(n + 1));
  while (m--) {
    int a, b;
    cin >> a >> b;
    path[a][b] = true;
    path[b][a] = true;
  }

  visited = vector<bool>(n + 1);
  DFS(v);
  print();

  visited = vector<bool>(n);
  BFS(v);
  return 0;
}
