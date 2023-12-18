#include <iostream>

using namespace std;

int N, K;

int solve() {
    for (int i = 1; i <= N; i++) {
        if (N % i) continue;
        if (--K) continue;

        return i;
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    cout << solve();

    return 0;
}
