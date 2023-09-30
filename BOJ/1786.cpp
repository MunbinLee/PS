#include <iostream>
#include <vector>

using namespace std;

int tSize, pSize;
string t, p;
vector<int> lps;
vector<int> pos;

void readAlabama() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  getline(cin, t);
  getline(cin, p);
  lps = vector<int>(t.size());
  tSize = (int) t.size();
  pSize = (int) p.size();
}

bool isPS(int left, int right, int i) {
  while (right <= i) {
    if (t[left] != t[right]) return false;
    left++;
    right++;
  }
  return true;
}

void computeLPS() {
  int right;
  for (int i = 1; i < t.size(); i++) {
    right = i / 2 + 1;
    while (right <= i) {
      if (isPS(0, right, i)) {
        lps[i] = i - right + 1;
        break;
      }
      right++;
    }
  }
}

void KMP() {
  computeLPS();
  int i = 0;
  int j = 0;
  while (i < tSize) {
    if (t[i] == p[j]) {
      i++;
      j++;
      if (j == pSize) {
        pos.emplace_back(i - j);
        j = lps[j];
      }
    } else {
      j = lps[j];
      if (j < 0) {
        i++;
        j++;
      }
    }
  }
}

int main() {
  input();
  KMP();
  cout << pos.size() << '\n';
  for (int i: pos) {
    cout << i + 1 << ' ';
  }
  return 0;
}
