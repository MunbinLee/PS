#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numComputer, numNetwork;
    cin >> numComputer >> numNetwork;

    vector<vector<int>> paths(numComputer + 1);

    while (numNetwork--) {
        int a, b;
        cin >> a >> b;
        paths[a].emplace_back(b);
        paths[b].emplace_back(a);
    }

    queue<int> q;
    q.emplace(1);
    vector<bool> visited(numComputer + 1);
    visited[1] = true;
    int answer = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next: paths[cur]) {
            if (visited[next]) continue;

            visited[next] = true;
            q.emplace(next);
            answer++;
        }
    }

    cout << answer;

    return 0;
}
