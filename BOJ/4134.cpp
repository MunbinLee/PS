#include <iostream>

using namespace std;

bool isPrime(long x) {
    if (x == 0 || x == 1) return false;

    for (long i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long n;
        cin >> n;

        for (long i = n;; i++) {
            if (!isPrime(i)) continue;
            cout << i << '\n';
            break;
        }
    }

    return 0;
}
