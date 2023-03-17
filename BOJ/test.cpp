#include <iostream>

using namespace std;
constexpr size_t n = 5;

int a[n] = {1,2,3,4,5};

int segtree[2 * n];

void init() {
  for (size_t i = 0; i < n; ++i) {
    segtree[i + n] = a[i];
  }

  for (size_t i = n - 1; i != 0; --i) {
    segtree[i] = segtree[i << 1] + segtree[i << 1 | 1];
  }
}

void update(size_t i, int x) {
  i+=n-1;
  segtree[i] = x;

  while (i >>= 1) {

    segtree[i] = segtree[i << 1] + segtree[i << 1 | 1];

  }

}

int query(size_t l, size_t r) {

  int result = 0;
  l+=n-1;
  r+=n;
  for (; l != r; l >>= 1, r >>= 1) {

    if (l & 1) result += segtree[l++];

    if (r & 1) result += segtree[--r];

  }

  return result;

}

int main() {
  init();
  update(3,6); // 3,6
  cout << query(2,5); // a2-a5 합 (17)
  return 0;
}
