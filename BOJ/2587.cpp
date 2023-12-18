#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    array<int, 5> arr; // NOLINT

    for (int &i: arr) {
        cin >> i;
    }

    sort(arr.begin(), arr.end());

    int sum = accumulate(arr.begin(), arr.end(), 0);

    cout << sum / 5 << '\n' << arr[2];

    return 0;
}
