#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;

    vector<vector<int>> board(M, vector<int>(N));

    for (auto &row: board) {
        for (int &cell: row) {
            cin >> cell;
        }
    }

    auto compress = [&](vector<int> &row) {
        set<int> numSet(row.begin(), row.end());
        unordered_map<int, int> compressMap;
        int numCompress = 0;

        for (int num: numSet) {
            compressMap[num] = numCompress++;
        }

        for (int &cell: row) {
            cell = compressMap[cell];
        }
    };

    for (auto &row: board) {
        compress(row);
    }

    vector<bool> visited(M);

    auto isSame = [&](int a, int b) {
        for (int i = 0; i < N; i++) {
            if (board[a][i] != board[b][i]) return false;
        }

        return true;
    };

    int answer = 0;

    for (int i = 0; i + 1 < M; i++) {
        int same = 1;

        for (int j = i + 1; j < M; j++) {
            if (visited[j]) continue;
            if (!isSame(i, j)) continue;

            visited[j] = true;
            same++;
        }

        if (same == 1) continue;

        answer += same * (same - 1) / 2;
    }

    cout << answer;

    return 0;
}
