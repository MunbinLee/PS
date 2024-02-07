#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <unordered_map>

using namespace std;

enum {
    CLEAN = '.',
    DIRTY = '*',
    WALL = 'x',
    START = 'o'
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, -1, 0, 1};

    auto solve = [&](int w, int h) {
        vector<string> board(h);
        vector<pair<int, int>> dirtyPositions;
        int sy = -1;
        int sx = -1;

        for (int y = 0; y < h; y++) {
            cin >> board[y];

            for (int x = 0; x < w; x++) {
                char &cell = board[y][x];

                if (cell == DIRTY) {
                    dirtyPositions.emplace_back(y, x);
                    continue;
                }

                if (cell == START) {
                    cell = CLEAN;
                    sy = y;
                    sx = x;
                }
            }
        }

        using tp = tuple<int, int, int, int>;
        queue<tp> q;
        q.emplace(sy, sx, 0, (1 << dirtyPositions.size()) - 1);

        vector<vector<unordered_map<int, bool>>> visited(h, vector<unordered_map<int, bool>>(w));
        visited[0][0][(1 << dirtyPositions.size()) - 1] = true;

        while (!q.empty()) {
            auto [cy, cx, count, cmask] = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int ny = cy + dy[dir];
                int nx = cx + dx[dir];

                if (ny == -1 || ny == h || nx == -1 || nx == w) continue;
                if (board[ny][nx] == WALL) continue;

                int nmask = cmask;

                for (int i = 0; i < dirtyPositions.size(); i++) {
                    if (ny == dirtyPositions[i].first & nx == dirtyPositions[i].second) {
                        nmask = cmask & ~(1 << i);
                        break;
                    }
                }

                if (visited[ny][nx][nmask]) continue;
                if (nmask == 0) return count + 1;

                visited[ny][nx][nmask] = true;
                q.emplace(ny, nx, count + 1, nmask);
            }
        }

        return -1;
    };

    int w, h;
    cin >> w >> h;

    while (w) {
        cout << solve(w, h) << '\n';

        cin >> w >> h;
    }

    return 0;
}
