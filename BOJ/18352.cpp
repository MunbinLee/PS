#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K, X;
    cin >> N >> M >> K >> X;

    vector<vector<int>> paths(N + 1);

    while (M--) {
        int A, B;
        cin >> A >> B;
        paths[A].emplace_back(B);
    }

    vector<int> minDists(N + 1, 987654321);
    minDists[X] = 0;

    queue<pair<int, int>> q;
    q.emplace(X, 0);

    while (!q.empty()) {
        auto [cur, dist] = q.front();
        q.pop();
        int ndist = dist + 1;

        for (int next: paths[cur]) {
            if (ndist >= minDists[next]) continue;
            minDists[next] = ndist;
            q.emplace(next, ndist);
        }
    }

    bool none = true;

    for (int i = 1; i <= N; i++) {
        if (minDists[i] != K) continue;
        none = false;
        cout << i << '\n';
    }

    if (none) {
        cout << "-1";
    }

    return 0;
}
