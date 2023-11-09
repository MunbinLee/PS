#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pos = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> board(N, vector<int>(M));

    for (auto &v: board) {
        for (int &i: v) {
            cin >> i;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

        }
    }


    return 0;
}
