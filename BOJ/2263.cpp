#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> in, post, pre, visited;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  in = vector<int>(n);
  post = vector<int>(n);
  pre = vector<int>(n);
  visited = vector<int>(n + 1);

  for (int &i: in) cin >> i;
  for (int &i: post) cin >> i;
}

void solve() {
  int root = post[n - 1];
  visited[root] = true;
  pre[0] = root;

  int right = in[n - 1];
  visited[right] = true;
  pre[n - 1] = right;

  int postIdx = n - 1;
  int inIdx = n - 1;
  int size = 0;
}

void output() {
  for (int i: pre) cout << i << ' ';
}

int main() {
  input();
  solve();
  output();
  return 0;
}
