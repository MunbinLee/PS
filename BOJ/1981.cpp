#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n));

    for (auto &row: board) {
        for (auto &cell: row) {
            cin >> cell;
        }
    }

    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, -1, 0, 1};

    auto bfs = [&](int diff) {
        for (int mn = 0; mn + diff <= 200; mn++) {
            int mx = mn + diff;

            if (board[0][0] > mx) continue;
            if (board[0][0] < mn) continue;

            vector<vector<bool>> visited(n, vector<bool>(n));
            visited[0][0] = true;

            using tp = tuple<int, int>;
            queue<tp> q;
            q.emplace(0, 0);

            while (!q.empty()) {
                auto [cy, cx] = q.front();
                q.pop();

                if (cy == n - 1 && cx == n - 1) return true;

                for (int dir = 0; dir < 4; dir++) {
                    int ny = cy + dy[dir];
                    int nx = cx + dx[dir];

                    if (ny == -1 || ny == n || nx == -1 || nx == n) continue;
                    if (visited[ny][nx]) continue;
                    if (board[ny][nx] > mx) continue;
                    if (board[ny][nx] < mn) continue;

                    visited[ny][nx] = true;
                    q.emplace(ny, nx);
                }
            }
        }

        return false;
    };

    int lo = 0;
    int hi = 200;
    int answer = -1;

    while (lo <= hi) {
        int md = (lo + hi) / 2;

        if (bfs(md)) {
            answer = md;
            hi = md - 1;
        } else {
            lo = md + 1;
        }
    }

    cout << answer;

    return 0;
}
