#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

vector<int> costs(N + 1), indegrees(N + 1), times(N + 1);
vector<vector<int>> children(N + 1);
queue<int> q;
int maxTime = 0;

for (int child = 1; child <= N; child++) {
    cin >> costs[child] >> indegrees[child];
    if (indegrees[child] == 0) {
        times[child] = costs[child];
        maxTime = max(maxTime, times[child]);
        q.emplace(child);
    }

    for (int i = 0; i < indegrees[child]; i++) {
        int parent;
        cin >> parent;
        children[parent].emplace_back(child);
    }
}

while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (int child: children[cur]) {
        times[child] = max(times[child], times[cur]);
        if (--indegrees[child] != 0) continue;
        times[child] += costs[child];
        maxTime = max(maxTime, times[child]);
        q.emplace(child);
    }
}

    cout << maxTime;

    return 0;
}
