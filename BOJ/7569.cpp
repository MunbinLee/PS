#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
using tp = tuple<int, int, int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N, H;
    cin >> M >> N >> H;

    vector<vector<vector<int>>> board(M, vector<vector<int>>(N, vector<int>(H)));
    queue<tp> q;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                int &tomato = board[k][j][i];
                cin >> tomato;

                if (tomato != 1) continue;
                q.emplace(1, k, j, i);
            }
        }
    }

    int dx[6] = {-1, 0, 1, 0, 0, 0};
    int dy[6] = {0, -1, 0, 1, 0, 0};
    int dz[6] = {0, 0, 0, 0, -1, 1};

    int answer = 0;

    while (!q.empty()) {
        auto [cur, x, y, z] = q.front();
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (nx == -1 || nx == M || ny == -1 || ny == N || nz == -1 || nz == H) continue;
            if (board[nx][ny][nz] != 0) continue;

            board[nx][ny][nz] = cur + 1;
            answer = cur;
            q.emplace(cur + 1, nx, ny, nz);
        }
    }

    auto solve = [&]() {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < M; k++) {
                    if (board[k][j][i] == 0) return -1;
                }
            }
        }

        return answer;
    };

    cout << solve();

    return 0;
}
