#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C;
    cin >> R >> C;

    vector<vector<int>> board(R, vector<int>(C));
    vector<pair<int, int>> swans;

    const int INF = 987654321;

    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            char ch;
            cin >> ch;

            if (ch == 'X') {
                board[y][x] = INF;
                continue;
            }

            if (ch == 'L') {
                board[y][x] = 0;
                swans.emplace_back(y, x);
            }
        }
    }

    using tp = tuple<int, int, int>;
    queue<tp> q;

    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            if (board[y][x] != 0) continue;

            q.emplace(y, x, 0);
        }
    }

    const int dy[4] = {-1, 0, 0, 1};
    const int dx[4] = {0, -1, 1, 0};

    while (!q.empty()) {
        auto [cy, cx, cost] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            int ncost = cost + 1;

            if (ny == -1 || ny == R || nx == -1 || nx == C) continue;
            if (ncost >= board[ny][nx]) continue;

            board[ny][nx] = ncost;
            q.emplace(ny, nx, ncost);
        }
    }

    auto [y, x] = swans[0];

    vector<vector<int>> minDists(R, vector<int>(C, INF));
    minDists[y][x] = 0;

    priority_queue<tp, vector<tp>, greater<>> pq;
    pq.emplace(0, y, x);

    while (!pq.empty()) {
        auto [dist, cy, cx] = pq.top();
        pq.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny == -1 || ny == R || nx == -1 || nx == C) continue;

            int ndist = max(dist, board[ny][nx]);

            if (ndist >= minDists[ny][nx]) continue;

            minDists[ny][nx] = ndist;
            pq.emplace(ndist, ny, nx);
        }
    }

    auto [ty, tx] = swans[1];

    cout << minDists[ty][tx];

    return 0;
}
