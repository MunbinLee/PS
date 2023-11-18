#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N, M;
vector<vector<pair<int, int>>> parents;
vector<bool> checked;
vector<map<int, int>> memo;

map<int, int> dfs(int x) {
    if (checked[x]) return memo[x];

    checked[x] = true;
    map<int, int> mp;

    for (auto [next, cnt]: parents[x]) {
        for (auto [k, v]: dfs(next)) {
            mp[k] += v * cnt;
        }
    }

    return memo[x] = mp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    parents.resize(N + 1);
    checked.resize(N + 1);
    memo.resize(N + 1);

    while (M--) {
        int X, Y, K;
        cin >> X >> Y >> K;
        parents[X].emplace_back(Y, K);
    }

    for (int i = 1; i <= N; i++) {
        if (!parents[i].empty()) continue;
        checked[i] = true;
        memo[i][i] = 1;
    }

    for (auto [k, v]: dfs(N)) {
        cout << k << ' ' << v << '\n';
    }

    return 0;
}
