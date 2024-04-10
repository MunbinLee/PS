#include <iostream>
#include <functional>
#include <unordered_map>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<int, unordered_map<int, int>> memo;

    for (int i = 0; i <= 9; i++) {
        memo[i][1] = 1;
    }

    int MOD = 1e9;

    function<int(int, int)> dp = [&](int head, int digit) {
        if (memo.contains(head) && memo[head].contains(digit)) {
            return memo[head][digit];
        }

        if (head == 0) {
            return memo[head][digit] = dp(1, digit - 1);
        }

        if (head == 9) {
            return memo[head][digit] = dp(8, digit - 1);
        }

        return memo[head][digit] = (dp(head - 1, digit - 1) + dp(head + 1, digit - 1)) % MOD;
    };

    int N;
    cin >> N;

    int answer = 0;

    for (int i = 1; i <= 9; i++) {
        answer += dp(i, N);
        answer %= MOD;
    }

    cout << answer;

    return 0;
}
