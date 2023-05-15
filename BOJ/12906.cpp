#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <map>

using namespace std;

typedef tuple<int, string, string, string> tp;

string A, B, C;
map<tuple<string, string, string>, bool> visited;

void input() {
  int a, b, c;
  cin >> a;
  if (a) cin >> A;
  cin >> b;
  if (b) cin >> B;
  cin >> c;
  if (c) cin >> C;
}

bool isCorrect(string &s1, string &s2, string &s3) {
  if (!ranges::all_of(s1, [](char ch) { return ch == 'A'; })) return false;
  if (!ranges::all_of(s2, [](char ch) { return ch == 'B'; })) return false;
  if (!ranges::all_of(s3, [](char ch) { return ch == 'C'; })) return false;
  return true;
}

bool move(string &from, string &to) {
  if (from.empty()) return false;
  to.push_back(from.back());
  from.pop_back();
  return true;
}

bool trans(int i, string &s1, string &s2, string &s3) {
  if (i == 0) return move(s1, s2);
  if (i == 1) return move(s1, s3);
  if (i == 2) return move(s2, s1);
  if (i == 3) return move(s2, s3);
  if (i == 4) return move(s3, s1);
  if (i == 5) return move(s3, s2);
}

void BFS() {
  queue<tp> q;
  q.emplace(0, A, B, C);

  while (!q.empty()) {
    auto [cnt, s1, s2, s3] = q.front();
    q.pop();
    if (isCorrect(s1, s2, s3)) {
      cout << cnt;
      return;
    }
    for (int i = 0; i < 6; i++) {
      string t1 = s1;
      string t2 = s2;
      string t3 = s3;
      if (trans(i, t1, t2, t3) && !visited[{t1, t2, t3}]) {
        visited[{t1, t2, t3}] = true;
        q.emplace(cnt + 1, t1, t2, t3);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  input();
  BFS();

  return 0;
}