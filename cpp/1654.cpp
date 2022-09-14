#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n;
    cin >> k >> n;
    vector<int> v(k);
    int high = 0;

    for (int &i : v) {
        cin >> i;
        high = max(high, i);
    }

    long long low = 1;
    int res = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;
        int cnt = 0;

        for (int i : v) cnt += i / mid;

        if (cnt >= n) {
            low = mid + 1;
            if (mid > res) res = mid;
        } else {
            high = mid - 1;
        }
    }

    cout << res;
    return 0;
}
