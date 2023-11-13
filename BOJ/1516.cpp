#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> costs, times;
vector<vector<int>> parents;

void input() {
    cin >> N;
    costs.resize(N + 1);
    times.resize(N + 1);
    parents.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> costs[i];

        int parent;
        cin >> parent;
        while (parent != -1) {
            parents[i].emplace_back(parent);
            cin >> parent;
        }
    }
}

int getTime(int x) {
    if (times[x]) return times[x];

    int maxTime = 0;
    for (int p: parents[x]) {
        maxTime = max(maxTime, getTime(p));
    }

    return times[x] = maxTime + costs[x];
}

void solve() {
    for (int i = 1; i <= N; i++) {
        cout << getTime(i) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solve();

    return 0;
}
