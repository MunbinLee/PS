#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    for (cin >> n; n != -1; cin >> n) {
        vector<int> prefixDivisors;
        stack<int> suffixDivisors;
        int sum = 1;
        int i = 2;

        for (; i * i < n; i++) {
            if (n % i) continue;

            prefixDivisors.emplace_back(i);
            suffixDivisors.emplace(n / i);
            sum += i + n / i;
        }

        if (i * i == n) {
            prefixDivisors.emplace_back(i);
            sum += i;
        }

        if (sum != n) {
            cout << n << " is NOT perfect.\n";
            continue;
        }

        cout << n << " = 1";

        for (int prefixDivisor: prefixDivisors) {
            cout << " + " << prefixDivisor;
        }

        while (!suffixDivisors.empty()) {
            int suffixDivisor = suffixDivisors.top();
            suffixDivisors.pop();
            cout << " + " << suffixDivisor;
        }

        cout << '\n';
    }

    return 0;
}
