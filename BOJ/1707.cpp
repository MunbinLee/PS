#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;

    while (K--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> paths(V + 1);

        while (E--) {
            int u, v;
            cin >> u >> v;

            paths[u].emplace_back(v);
            paths[v].emplace_back(u);
        }

        vector<int> states(V + 1, -1);

        for (int i = 1; i <= V; i++) {
            if (states[i] != -1) continue;

            queue<pair<int, int>> q;
            q.emplace(i, !!states[i]);

            while (!q.empty()) {
                auto [cur, state] = q.front();

                if (states[cur] != -1 && states[cur] != state) {
                    cout << "NO\n";
                    goto ENDOFTEST;
                }

                if (states[cur] != -1) continue;

                states[cur] = state;

                for (int next: paths[cur]) {
                    if (states[cur] != -1 && states[cur] != state) {
                        cout << "NO\n";
                        goto ENDOFTEST;
                    }

                    if (states[next] != -1) continue;

                    q.emplace(next, !state);
                }
            }
        }

        cout << "YES\n";

        ENDOFTEST:;
    }

    return 0;
}
