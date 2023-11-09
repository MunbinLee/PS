#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<bool> isBroken(10);
    while (m--) {
        int num;
        cin >> num;
        isBroken[num] = true;
    }

    // +, -만 사용
    int minCnt = abs(n - 100);

    queue<int> q;
    q.emplace(0);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (!(cur == 0 && isBroken[0])) {
            int cnt = (int) to_string(cur).size() + abs(n - cur);
            minCnt = min(minCnt, cnt);
        }
        for (int i = 0; i <= 9; i++) {
            if (isBroken[i]) continue;
            if (cur == 0 && i == 0) continue;
            int next = cur * 10 + i;
            if (next > 1'000'000) continue;
            q.emplace(cur * 10 + i);
        }
    }

    cout << minCnt;

    return 0;
}
