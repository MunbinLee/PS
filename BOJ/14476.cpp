#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> segTree;

int getGCD(int a, int b) {
  if (a == -1) return b;
  if (b == -1) return a;

  if (b == 0) return a;
  return getGCD(b, a % b);
}

void input() {
  cin >> n;
  segTree.resize(n * 2);
  for (int i = 0; i < n; i++) {
    cin >> segTree[n + i];
  }
  for (int i = n - 1; i > 0; i--) {
    segTree[i] = getGCD(segTree[i * 2], segTree[i * 2 + 1]);
  }
}

void update(int key, int value) {
  key += n;
  segTree[key] = value;
  while (key /= 2) {
    segTree[key] = getGCD(segTree[key * 2], segTree[key * 2 + 1]);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  input();
  int maxGCD = -1;
  int maxK;
  for (int i = 0; i < n; i++) {
    int k = segTree[n + i];
    update(i, -1);
    int gcd = segTree[1];
    if (k % gcd && gcd > maxGCD) {
      maxGCD = gcd;
      maxK = k;
    }
    update(i, k);
  }

  cout << maxGCD;
  if (maxGCD != -1) cout << ' ' << maxK;
  return 0;
}
