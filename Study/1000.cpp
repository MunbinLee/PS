#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i: v) cin >> i;
  int k;
  cin >> k;

  int left = 0;
  int right = n - 1;
  int mnDiff = INT32_MAX; // k와의 최소 차이
  int cnt = 0; // k에 가장 가까운 정수쌍의 개수

  while (left != right) {
    int sum = v[left] + v[right];
    int diff = abs(sum - k);

    if (diff < mnDiff) {
      mnDiff = diff;
      cnt = 1;
    } else if (diff == mnDiff) cnt++;

    (sum > k) ? right-- : left++;
    // 오른쪽 인덱스를 왼쪽으로 옮기면 sum이 작아진다.
    // 왼쪽 인덱스를 오른쪽으로 옮기면 sum이 커진다.
  }

  cout << cnt;
  return 0;
}
