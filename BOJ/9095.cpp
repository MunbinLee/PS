#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> memo(11, -1);
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 2;
    memo[3] = 4;

    function<int(int)> dp = [&](int x) {
        int &m = memo[x];

        if (m != -1) {
            return m;
        }

        return m = dp(x - 1) + dp(x - 2) + dp(x - 3);
    };

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        cout << dp(n) << '\n';
    }

    return 0;
}
