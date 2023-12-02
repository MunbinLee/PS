#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> indegrees(N + 1);
    vector<vector<int>> children(N + 1);

    while (M--) {
        int A, B;
        cin >> A >> B;
        indegrees[B]++;
        children[A].emplace_back(B);
    }

priority_queue<int, vector<int>, greater<>> pq;

for (int i = 1; i <= N; i++) {
    if (indegrees[i] != 0) continue;
    pq.emplace(i);
}

while (!pq.empty()) {
    int cur = pq.top();
    pq.pop();

    cout << cur << ' ';

    for (int child: children[cur]) {
        if (--indegrees[child] != 0) continue;
        pq.emplace(child);
    }
}

    return 0;
}