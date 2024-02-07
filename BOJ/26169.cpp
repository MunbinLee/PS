#include <iostream>
#include <array>
#include <functional>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    enum {
        APPLE = 1,
        EMPTY = 0,
        WALL = -1
    };

    array<array<int, 5>, 5> board; // NOLINT

    for (auto &row: board) {
        for (int &cell: row) {
            cin >> cell;
        }
    }

    array<int, 4> dy{-1, 0, 1, 0}, dx{0, -1, 0, 1};

    function<int(int, int, int, int)> dfs = [&](int cy, int cx, int cmove, int capple) {
        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny == -1 || ny == 5 || nx == -1 || nx == 5) continue;

            int cell = board[ny][nx];

            if (cell == WALL) continue;

            int napple = capple + (cell == APPLE);
            if (napple == 2) return 1;
            if (cmove + 1 == 3) continue;

            board[cy][cx] = WALL;

            if (dfs(ny, nx, cmove + 1, napple)) return 1;

            board[cy][cx] = cell;
        }

        return 0;
    };

    int r, c;
    cin >> r >> c;

    cout << dfs(r, c, 0, 0);

    return 0;
}
