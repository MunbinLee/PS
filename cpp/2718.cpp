#include <iostream>

using namespace std;

int dp[1001] = {1, 1, 5, 11};

int DP(int n) {
    if (dp[n] == 0) {
        dp[n] = DP(n - 1) + DP(n - 2) * 5 + DP(n - 3) - DP(n - 4);
    }
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int num;
        cin >> num;
        cout << DP(num) << '\n';
    }
    return 0;
}
