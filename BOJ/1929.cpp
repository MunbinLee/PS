#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;
    vector<bool> isPrime(n + 1, true);
    isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= n; j += i) {
            isPrime[j] = false;
        }
    }

    for (int i = m; i <= n; i++) {
        if (isPrime[i]) cout << i << '\n';
    }
    return 0;
}
