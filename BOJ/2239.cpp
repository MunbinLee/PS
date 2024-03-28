#include <iostream>
#include <array>
#include <functional>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    array<array<int, 9>, 9> board{};
    array<array<bool, 9>, 10> visitedRow{}, visitedCol{}, visitedBox{};

    auto getBox = [](int y, int x) {
        return y / 3 * 3 + x / 3;
    };

    for (int y = 0; y < 9; y++) {
        string s;
        cin >> s;

        for (int x = 0; x < 9; x++) {
            int &cell = board[y][x];
            cell = s[x] - '0';

            if (cell) {
                visitedRow[y][cell] = true;
                visitedCol[x][cell] = true;
                visitedBox[getBox(y, x)][cell] = true;
            }
        }
    }

    function<void(int)> dfs = [&](int index) {
        if (index == 81) {
            for (auto &row: board) {
                for (int item: row) {
                    cout << item;
                }
                cout << '\n';
            }
            exit(0);
        }

        int y = index / 9;
        int x = index % 9;
        int &cell = board[y][x];

        if (cell) {
            dfs(index + 1);
            return;
        }

        for (int i = 1; i <= 9; i++) {
            if (visitedRow[y][i]) continue;
            if (visitedCol[x][i]) continue;
            if (visitedBox[getBox(y, x)][i]) continue;

            visitedRow[y][i] = true;
            visitedCol[x][i] = true;
            visitedBox[getBox(y, x)][i] = true;
            cell = i;

            dfs(index + 1);

            visitedRow[y][i] = false;
            visitedCol[x][i] = false;
            visitedBox[getBox(y, x)][i] = false;
            cell = 0;
        }
    };

    dfs(0);
}