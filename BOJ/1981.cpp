#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n));

    for (auto &row: board) {
        for (int &i: row) {
            cin >> i;
        }
    }

    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, -1, 0, 1};

    auto bfs = [&](int targetMin, int targetMax) {
        if (board[0][0] < targetMin) return false;
        if (board[0][0] > targetMax) return false;

        vector<vector<bool>> visited(n, vector<bool>(n));
        visited[0][0] = true;

        queue<pair<int, int>> q;
        q.emplace(0, 0);

        while (!q.empty()) {
            auto [cy, cx] = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int ny = cy + dy[dir];
                int nx = cx + dx[dir];

                if (ny == -1 || ny == n || nx == -1 || nx == n) continue;

                if (visited[ny][nx]) continue;
                if (board[ny][nx] < targetMin) continue;
                if (board[ny][nx] > targetMax) continue;
                if (ny == n - 1 && nx == n - 1) return true;

                visited[ny][nx] = true;
                q.emplace(ny, nx);
            }
        }

        return false;
    };

    // 0 ~ 200
    // 가장 널널한 케이스 : 0, 200
    // 0,0 ~ 200,200 201*201=40401
    // 0-> 0:200
    //      21  ~~1Q`


    int lo = 0;
    int hi = 40401;

    while (lo < hi) {
        int md = (lo + hi) / 2;

        int targetMin = md / 200;
        int targetMax = md % 200;

        if (bfs(targetMin, targetMax)) {
            hi = md;
        } else {
            lo = md + 1;
        }
    }

    cout << lo;

//    int lo = 0;
//    int hi = 6;
//
//    while (lo < hi) {
//        int md = lo + (hi - lo) / 2;
//
//        if (bfs(md)) {
//            hi = md;
//        } else {
//            lo = md + 1;
//        }
//    }
//
//    cout << lo;

    // 최대 - 최소의 최솟값을 출력한다.
    // 다익스트라 비슷하게 좌표별 최댓값, 최솟값 저장?
    // 최대 - 최소를 그리디하게 최적값을 구할 수 없기 때문에 리스트를 만들어야 함.
    // -> 다익스트라면 O(N^2 log N) 시간초과
    // vertex == N, O(N^2) 가능
    // BFS 한 번 돌리면 O(N)
    // 최대 - 최소는 0~200
    // BFS 200번 돌려도 됨
    // 이분탐색으로 돌리면 log 200번으로 줄어듦

    return 0;
}
