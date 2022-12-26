#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> v;
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            int priority;
            cin >> priority;
            v.emplace_back(priority);
            q.emplace(i, priority);
        }

        sort(v.begin(), v.end());

        int cnt = 0;
        while (true) {
            if (v.back() == q.front().second) {
                cnt++;
                if (m == q.front().first) break;
                v.pop_back();
            }
            else
                q.emplace(q.front());
            q.pop();
        }
        cout << cnt << '\n';
    }
    return 0;
}
