#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> segTreeEven, segTreeOdd;

void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  segTreeEven.resize(n * 2);
  segTreeOdd.resize(n * 2);
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    if (tmp % 2) segTreeOdd[n + i] = 1;
    else segTreeEven[n + i] = 1;
  }
  for (int i = n - 1; i > 0; i--) {
    segTreeEven[i] = segTreeEven[i * 2] + segTreeEven[i * 2 + 1];
    segTreeOdd[i] = segTreeOdd[i * 2] + segTreeOdd[i * 2 + 1];
  }
  cin >> m;
}

void update(int key, int value) {
  key += n - 1;
  if (value % 2) {
    segTreeOdd[key] = 1;
    segTreeEven[key] = 0;
  } else {
    segTreeEven[key] = 1;
    segTreeOdd[key] = 0;
  }
  while (key /= 2) {
    segTreeEven[key] = segTreeEven[key * 2] + segTreeEven[key * 2 + 1];
    segTreeOdd[key] = segTreeOdd[key * 2] + segTreeOdd[key * 2 + 1];
  }
}

pair<int, int> query(int start, int end) {
  int even = 0;
  int odd = 0;
  start += n - 1;
  end += n;
  while (start != end) {
    if (start % 2) {
      even += segTreeEven[start];
      odd += segTreeOdd[start];
      start++;
    }
    if (end % 2) {
      end--;
      even += segTreeEven[end];
      odd += segTreeOdd[end];
    }
    start /= 2;
    end /= 2;
  }
  return {even, odd};
}

void solve() {
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1) update(b, c);
    else if (a == 2) cout << query(b, c).first << '\n';
    else if (a == 3) cout << query(b, c).second << '\n';
  }
}

int main() {
  input();
  solve();
  return 0;
}
