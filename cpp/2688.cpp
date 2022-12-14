#include <iostream>

using namespace std;

long long int dp[64][10] = {{10, 9, 8, 7, 6, 5, 4, 3, 2, 1}};

long long int DP(int r, int c) {
    if (dp[r][c] == 0) {
        for (int i = c; i < 10; i++) {
            dp[r][c] += DP(r - 1, i);
        }
    }
    return dp[r][c];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << DP(n - 1, 0) << '\n';
    }
    return 0;
}
