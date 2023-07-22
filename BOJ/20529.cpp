#include <iostream>
#include <vector>

using namespace std;

const int INF = 987654321;

int n;
vector<string> v;

int getDist(int a, int b) {
  string s1 = v[a];
  string s2 = v[b];
  int dist = 0;
  for (int i = 0; i < 4; i++) {
    dist += s1[i] != s2[i];
  }
  return dist;
}

int getDist(vector<int> &cur) {
  int dist = getDist(cur[0], cur[1]);
  dist += getDist(cur[0], cur[2]);
  dist += getDist(cur[1], cur[2]);
  return dist;
}

int combinate(int idx, vector<int> cur) {
  if (cur.size() == 3) return getDist(cur);
  if (idx == n) return INF;

  int minDist = combinate(idx + 1, cur);
  cur.emplace_back(idx);
  minDist = min(minDist, combinate(idx + 1, cur));
  return minDist;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    cin >> n;
    if (n > 32) {
      cout << "0\n";
      string dummy;
      cin.ignore();
      getline(cin, dummy);
      continue;
    }

    v.resize(n);
    for (string &s: v) {
      cin >> s;
    }

    cout << combinate(0, {}) << '\n';
  }
}