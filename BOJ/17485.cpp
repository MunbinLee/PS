#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(M));

    for (auto &row: board) {
        for (int &cost: row) {
            cin >> cost;
        }
    }

    const int INF = 987654321;

    array<vector<vector<int>>, 3> minDists;
    minDists.fill(vector(N, vector<int>(M, INF)));

    using tp = tuple<int, int, int, int>;
    priority_queue<tp, vector<tp>, greater<>> pq;

    for (int x = 0; x < M; x++) {
        pq.emplace(board[0][x], 0, x, -1);
    }

    const array<int, 3> dx{-1, 0, 1};

    while (!pq.empty()) {
        auto [dist, cy, cx, lastDir] = pq.top();
        pq.pop();

        for (int dir = 0; dir < 3; dir++) {
            if (dir == lastDir) continue;

            int ny = cy + 1;
            int nx = cx + dx[dir];

            if (ny == N || nx == -1 || nx == M) continue;

            int ndist = dist + board[ny][nx];

            if (ndist >= minDists[dir][ny][nx]) continue;

            minDists[dir][ny][nx] = ndist;
            pq.emplace(ndist, ny, nx, dir);
        }
    }
#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(M));

    for (auto &row: board) {
        for (int &cost: row) {
            cin >> cost;
        }
    }

    const int INF = 987654321;

    array<vector<vector<int>>, 3> minDists;
    minDists.fill(vector(N, vector<int>(M, INF)));

    using tp = tuple<int, int, int, int>;
    priority_queue<tp, vector<tp>, greater<>> pq;

    for (int x = 0; x < M; x++) {
        pq.emplace(board[0][x], 0, x, -1);
    }

    const array<int, 3> dx{-1, 0, 1};

    while (!pq.empty()) {
        auto [dist, cy, cx, lastDir] = pq.top();
        pq.pop();

        for (int dir = 0; dir < 3; dir++) {
            if (dir == lastDir) continue;

            int ny = cy + 1;
            int nx = cx + dx[dir];

            if (ny == N || nx == -1 || nx == M) continue;

            int ndist = dist + board[ny][nx];

            if (ndist >= minDists[dir][ny][nx]) continue;

            minDists[dir][ny][nx] = ndist;
            pq.emplace(ndist, ny, nx, dir);
        }
    }

    int answer = INF;

    for (int x = 0; x < M; x++) {
        for (auto minDist: minDists) {
            answer = min(answer, minDist[N - 1][x]);
        }
    }

    cout << answer;

    return 0;
}

    int answer = INF;

    for (int x = 0; x < M; x++) {
        for (auto minDist: minDists) {
            answer = min(answer, minDist[N - 1][x]);
        }
    }

    cout << answer;

    return 0;
}
