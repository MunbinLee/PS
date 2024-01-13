#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, E;
    cin >> N >> E;

    using pr = pair<int, int>;
    vector<vector<pr>> paths(N + 1);

    while (E--) {
        int a, b, cost;
        cin >> a >> b >> cost;

        paths[a].emplace_back(cost, b);
        paths[b].emplace_back(cost, a);
    }

    int v1, v2;
    cin >> v1 >> v2;

    const int INF = 98765432;

    auto dijkstra = [&](int begin, int end) {
        vector<int> minDists(N + 1, INF);
        minDists[begin] = 0;

        priority_queue<pr, vector<pr>, greater<>> pq;
        pq.emplace(0, begin);

        while (!pq.empty()) {
            auto [dist, cur] = pq.top();
            pq.pop();

            for (auto [cost, next]: paths[cur]) {
                int ndist = dist + cost;
                if (ndist >= minDists[next]) continue;
                minDists[next] = ndist;
                pq.emplace(ndist, next);
            }
        }

        return minDists[end];
    };

    int route1 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, N);
    int route2 = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, N);

    int answer = min(route1, route2);
    if (answer >= INF) answer = -1;

    cout << answer;

    return 0;
}