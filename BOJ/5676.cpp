#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> segTree;

int normalize(int num) {
  if (num > 0) num = 1;
  else if (num < 0) num = -1;
  else num = 0;
  return num;
}

bool input() {
  if (not cin >> n) return false;
  cin >> k;
  segTree.resize(n * 2);
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    segTree[n + i] = normalize(tmp);
  }
  for (int i = n - 1; i > 0; i--) {
    segTree[i] = segTree[i * 2] * segTree[i * 2 + 1];
  }
  return true;
}

void update(int key, int value) {
  key += n - 1;
  segTree[key] = normalize(value);
  while (key /= 2) {
    segTree[key] = segTree[key * 2] * segTree[key * 2 + 1];
  }
}

char query(int start, int end) {
  int res = 1;
  start += n - 1;
  end += n;
  while (start != end) {
    if (start % 2) {
      res *= segTree[start];
      start++;
    }
    if (end % 2) {
      end--;
      res *= segTree[end];
    }
    start /= 2;
    end /= 2;
  }
  if (res == 1) return '+';
  if (res == -1) return '-';
  return '0';
}

void solve() {
  while (k--) {
    char cmd;
    int a, b;
    cin >> cmd >> a >> b;
    if (cmd == 'C') update(a, b);
    else if (cmd == 'P') cout << query(a, b);
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  while (input()) {
    solve();
  }
  return 0;
}
