#include <iostream>
#include <array>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    array<bool, 123456 * 2 + 1> isPrime; // NOLINT;
    isPrime.fill(true);
    isPrime[1] = false;

    for (int i = 2; i * i < isPrime.size(); i++) {
        if (!isPrime[i]) continue;

        for (int j = i * i; j < isPrime.size(); j += i) {
            isPrime[j] = false;
        }
    }

    array<int, 123456 * 2 + 1> prefixSum{};

    for (int i = 1; i < prefixSum.size(); i++) {
        prefixSum[i] = prefixSum[i - 1] + isPrime[i];
    }

    auto solve = [&](int x) {
        return prefixSum[x * 2] - prefixSum[x];
    };

    int n;
    cin >> n;

    while (n) {
        cout << solve(n) << '\n';
        cin >> n;
    }

    return 0;
}
