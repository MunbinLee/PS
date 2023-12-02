#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int INF = 987654321;

int N, M;
vector<int> roots, leaders;
vector<unordered_map<int, bool>> paths;
unordered_map<int, vector<int>> groups;
unordered_map<int, int> dists;

int find(int x) { // NOLINT
    if (roots[x] == x) return x;

    return roots[x] = find(roots[x]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a > b) swap(a, b);
    roots[a] = b;
}

int bfs(int x, vector<int> &group) {
    dists.clear();
    dists[x] = 0;

    queue<int> q;
    q.emplace(x);
    int maxDist = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int next: group) {
            if (!paths[cur][next]) continue;
            if (dists.contains(next)) continue;
            dists[next] = dists[cur] + 1;
            maxDist = max(maxDist, dists[next]);
            q.emplace(next);
        }
    }

    return maxDist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    roots.resize(N + 1);
    iota(roots.begin(), roots.end(), 0);
    paths.resize(N + 1);

    while (M--) {
        int a, b;
        cin >> a >> b;
        paths[a][b] = true;
        paths[b][a] = true;
        merge(a, b);
    }

    for (int i = 1; i <= N; i++) {
        groups[find(i)].emplace_back(i);
    }

    leaders.reserve(groups.size());

    for (auto &[k, group]: groups) {
        int minDist = INF;
        int leader = -1;
        for (int i = 0; i < group.size(); i++) {
            int dist = bfs(group[i], group);
            if (dist < minDist) {
                minDist = dist;
                leader = group[i];
            }
        }
        leaders.emplace_back(leader);
    }

    sort(leaders.begin(), leaders.end());

    cout << groups.size() << '\n';

    for (int leader: leaders) {
        cout << leader << '\n';
    }

    return 0;
}
