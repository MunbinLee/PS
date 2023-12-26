#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> diffs(N - 1);

    int prev;
    cin >> prev;

    for (int i = 0; i < N - 1; i++) {
        int cur;
        cin >> cur;

        diffs[i] = cur - prev;

        prev = cur;
    }

    int divisor = diffs[0];

    for (int diff: diffs) {
        divisor = gcd(divisor, diff);
    }

    int answer = 0;

    for (int diff: diffs) {
        answer += diff / divisor - 1;
    }

    cout << answer;

    return 0;
}
