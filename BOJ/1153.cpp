#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<bool> isPrime(N, true);
    isPrime[0] = false;
    isPrime[1] = false;

    vector<int> primes;
    primes.reserve(N);

    for (int i = 2; i < N; i++) {
        if (!isPrime[i]) continue;

        primes.emplace_back(i);

        for (auto j = 1LL * i * i; j < N; j += i) {
            isPrime[j] = false;
        }
    }

    string prefix;

    if (N & 1) {
        N -= 5;
        prefix = "2 3 ";
    } else {
        N -= 4;
        prefix = "2 2 ";
    }

    for (int prime: primes) {
        if (N < prime) break;

        if (!isPrime[N - prime]) continue;

        cout << prefix << prime << ' ' << N - prime;
        return 0;
    }

    cout << "-1";
    return 0;
}
