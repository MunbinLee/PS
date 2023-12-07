#include <iostream>
#include <vector>
#include <queue>

#define int long long
#define INF 987654321

using namespace std;
using pr = pair<int, int>;

int N, E, v1, v2;
vector<vector<pr>> paths;
vector<int> minCosts;

int dijkstra(int begin, int end) {
    fill(minCosts.begin(), minCosts.end(), INF);
    minCosts[begin] = 0;
    priority_queue<pr, vector<pr>, greater<>> pq;
    pq.emplace(0, begin);

    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();

        for (auto [ncost, next]: paths[cur]) {
            ncost += cost;
            if (ncost >= minCosts[next]) continue;
            minCosts[next] = ncost;
            pq.emplace(ncost, next);
        }
    }

    return minCosts[end];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> E;
    paths.resize(N + 1);
    minCosts.resize(N + 1);

    while (E--) {
        int a, b, c;
        cin >> a >> b >> c;
        paths[a].emplace_back(c, b);
        paths[b].emplace_back(c, a);
    }

    cin >> v1 >> v2;

    int route1 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, N);
    int route2 = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, N);
    int answer = min(route1, route2);
    if (answer >= INF) answer = -1;

    cout << answer;

    return 0;
}
