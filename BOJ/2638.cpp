#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    auto board = vector(N, vector<int>(M));

    for (auto &row: board) {
        for (int &cell: row) {
            cin >> cell;
        }
    }

    queue<pair<int, int>> q;

    for (int y: {0, N - 1}) {
        for (int x = 0; x < M; x++) {
            if (board[y][x] != 0) continue;

            board[y][x] = -1;
            q.emplace(y, x);
        }
    }

    for (int x: {0, M - 1}) {
        for (int y = 0; y < N; y++) {
            if (board[y][x] != 0) continue;

            board[y][x] = -1;
            q.emplace(y, x);
        }
    }

    int dy[4]{-1, 0, 1, 0};
    int dx[4]{0, -1, 0, 1};

    while (!q.empty()) {
        auto [cy, cx] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny == -1 || ny == N || nx == -1 || nx == M) continue;
            if (board[ny][nx] != 0) continue;

            board[ny][nx] = -1;
            q.emplace(ny, nx);
        }
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (board[y][x] != 1) continue;

            int count = 0;

            for (int dir = 0; dir < 4; dir++) {
                int ny = y + dy[dir];
                int nx = x + dx[dir];

                if (ny == -1 || ny == N || nx == -1 || nx == M) continue;

                count += (board[ny][nx] == -1);
            }

            if (count < 2) continue;

            board[y][x] = -1;
            
        }
    }

    for (auto &row: board) {
        for (int &cell: row) {
            cout << cell << '\t';
        }
        cout << '\n';
    }

    return 0;
}
