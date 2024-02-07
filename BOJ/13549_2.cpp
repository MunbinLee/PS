#include <iostream>
#include <tuple>
#include <queue>
#include <array>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    if (N == K) {
        cout << '0';
        return 0;
    }

    if (N < K) swap(N, K);

    if (K == 0) {
        cout << N - K;
        return 0;
    }

    using tp = tuple<int, int>;
    queue<tp> q;
    q.emplace(N, 0);

    int INF = 987654321;
    vector<int> minTimes(100'003, INF);
    minTimes[N] = 0;
    minTimes[N + 2] = -1;

    while (!q.empty()) {
        auto [cur, time] = q.front();
        q.pop();

        {
            int next = cur;

            while (next % 2 == 0) {
                next /= 2;

                if (time >= minTimes[next]) continue;

                minTimes[next] = time;
                q.emplace(next, time);

                if (next == 0) break;
            }
        }

        for (int next: {cur - 1, cur + 1}) {
            if (next == -1) continue;
            if (time + 1 >= minTimes[next]) continue;

            minTimes[next] = time + 1;
            q.emplace(next, time + 1);
        }
    }

    cout << minTimes[K];

    return 0;
}