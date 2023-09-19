#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, k;
string binary;
vector<bool> visited;
set<string> answers;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k >> binary;
  visited = vector<bool>(n);
}

void dfs(string s, int dist) {
  if (dist == k) {
    answers.emplace(s);
    return;
  }

  for (int i = 0; i < n; i++) {
    if (visited[i]) continue;

    visited[i] = true;
    string ns = s;
    (ns[i] == '0') ? ns[i] = '1' : ns[i] = '0';
    dfs(ns, dist + 1);
    visited[i] = false;
  }
}

int main() {
  input();
  dfs(binary, 0);
  for (string s: answers) cout << s << '\n';
  return 0;
}
