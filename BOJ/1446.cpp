#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;
using pr = pair<int, int>;

int N, D;
unordered_map<int, bool> targets;
unordered_map<int, unordered_map<int, int>> shortcuts;
unordered_map<int, int> minDists;

void dijkstra() {
    priority_queue<pr, vector<pr>, greater<>> pq;
    pq.emplace(0, 0);

    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();

        for (auto [next, _]: targets) {
            if (cur >= next) continue;
            int ncost = cost + (shortcuts[cur].contains(next) ? shortcuts[cur][next] : next - cur);
            if (minDists.contains(next) && ncost > minDists[next]) continue;
            minDists[next] = ncost;
            pq.emplace(ncost, next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> D;
    targets[D] = true;

    while (N--) {
        int begin, end, dist;
        cin >> begin >> end >> dist;
        if (end > D) continue;
        if (dist >= end - begin) continue;
        targets[begin] = true;
        targets[end] = true;
        shortcuts[begin][end] = shortcuts[begin].contains(end) ? min(shortcuts[begin][end], dist) : dist;
    }

    dijkstra();

    cout << minDists[D];

    return 0;
}
