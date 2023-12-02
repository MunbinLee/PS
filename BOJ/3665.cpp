#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string solve() {
    int n;
    cin >> n;

    vector<int> t(n + 1);
    vector<vector<bool>> orders(n + 1, vector<bool>(n + 1));

    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }

    for (int i = 1; i + 1 <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int a = t[i];
            int b = t[j];
            orders[a][b] = true;
        }
    }

    int m;
    cin >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        orders[a][b] = !orders[a][b];
        orders[b][a] = !orders[b][a];
    }

    vector<int> indegrees(n + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!orders[i][j]) continue;
            indegrees[j]++;
        }
    }

    unordered_map<int, string> map;

    for (int i = 1; i <= n; i++) {
//    if (map.contains(indegrees[i])) return "IMPOSSIBLE";
        map[indegrees[i]] = to_string(i);
    }

    string res;

    for (int i = 0; i < n; i++) {
        if (!map.contains(i)) return "IMPOSSIBLE";
        res += map[i] + ' ';
    }

    return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC;
    cin >> TC;

    while (TC--) {
        cout << solve() << '\n';
    }

    return 0;
}
