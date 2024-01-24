#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> paths(N + 1), visited(N + 1);

        for (int i = 1; i <= N; i++) {
            cin >> paths[i];
        }

        int cycles = 0;

        for (int cur = 1; cur <= N; cur++) {
            if (visited[cur]) continue;

            visited[cur] = true;
            cycles++;
            int next = paths[cur];

            while (next != cur) {
                visited[next] = true;
                next = paths[next];
            }
        }

        cout << cycles << '\n';
    }

    return 0;
}
