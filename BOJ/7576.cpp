#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
using tp = tuple<int, int, int>;

enum {
    EMPTY = -1,
    UNRIPE = 0,
    RIPE = 1
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int dy[4] = {-1, 0, 0, 1};
    const int dx[4] = {0, -1, 1, 0};

    int M, N;
    cin >> M >> N;

    vector<vector<int>> board(N, vector<int>(M));
    queue<tp> q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] != RIPE) continue;
            q.emplace(i, j, 0);
        }
    }

    while (!q.empty()) {
        auto [cy, cx, day] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny == -1 || ny == N || nx == -1 || nx == M) continue;
            if (board[ny][nx] != UNRIPE) continue;
            q.emplace(ny, nx, day + 1);
        }
    }
    return 0;
}
