#include <iostream>
#include <array>

constexpr int primeMax = 1'000'000;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    array<bool, primeMax + 1> isPrime; // NOLINT
    isPrime.fill(true);

    for (int i = 2; i * i <= primeMax; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= primeMax; j += i) {
            isPrime[j] = false;
        }
    }

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int partition = 0;

        for (int i = 2; i <= N / 2; i++) {
            if (!isPrime[i]) continue;
            if (!isPrime[N - i]) continue;
            partition++;
        }

        cout << partition << '\n';
    }

    return 0;
}
