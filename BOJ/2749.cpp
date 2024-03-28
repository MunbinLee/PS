#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int PERIOD = 1'500'000;

    vector<int> fibo(PERIOD);
    fibo[1] = 1;

    for (int i = 2; i < PERIOD; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        fibo[i] %= 1'000'000;
    }

    long long n;
    cin >> n;

    cout << fibo[n % PERIOD];

    return 0;
}
