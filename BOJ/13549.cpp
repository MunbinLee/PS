#include <iostream>
#include <array>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    array<bool, 100'001> visited{};
    visited[100'000] = true;

    int N, K;
    cin >> N >> K;

    if (N >= K) {
        cout << N - K;

        return 0;
    }

    visited[K] = true;

    queue<pair<int, int>> q;
    q.emplace(K, 0);

    while (!q.empty()) {
        auto [cur, time] = q.front();
        q.pop();

        {
            int next = cur;

            while (next && next % 2 == 0) {
                next /= 2;

                if (next == N) {
                    cout << time;
                    return 0;
                }
                if (visited[next]) continue;

                visited[next] = true;
                q.emplace(next, time);
            }
        }


        for (int next: {cur - 1, cur + 1}) {
            if (next == N) {
                cout << time + 1;
                return 0;
            }
            
            if (next == -1) continue;
            if (visited[next]) continue;

            visited[next] = true;
            q.emplace(next, time + 1);
        }
    }

    return 0;
}
