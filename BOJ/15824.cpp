#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

constexpr long long MOD = 1'000'000'007;
unordered_map<int, long long> memo{
    {0, 1}
};

long long power(int x) {
    // NOLINT
    if (memo.contains(x)) return memo[x];

    if (x % 2) return memo[x] = power(x - 1) * 2 % MOD;

    return power(x / 2) * power(x / 2) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> foods(N);

    for (int &food: foods) {
        cin >> food;
    }

    ranges::sort(foods);

    long long answer = 0;

    for (int i = 0; i < N; i++) {
        answer += foods[i] * (power(i) - power(N - 1 - i));
        answer %= MOD;
    }

    cout << answer;

    return 0;
}
