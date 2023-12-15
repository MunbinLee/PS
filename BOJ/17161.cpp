#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string S, E;

void solve(int sy, int sx, int ey, int ex) {
    if (sy > ey || sx > ex) return;

    if (sy == ey) {
        for (int i = sx; i < ex; i++) {
            cout << "a " << E[i] << '\n';
        }
        return;
    }

    int my = (sy + ey) / 2;
    int len = ex - sx + 1;

    vector<vector<int>> upper(2, vector<int>(len));
    for (int i = sx; i <= ex; i++) {
        upper[1][i - sx] = i - sx;
    }

    for (int i = sy + 1; i <= my; i++) {
        for (int j = sx; j <= ex; j++) {
            upper[0][j - sx] = upper[1][j - sx];
        }

        upper[1][0] = i - sy;

        for (int j = sx + 1; j <= ex; j++) {
            if (S[i - 1] == E[j - 1]) {
                upper[1][j - sx] = upper[0][j - sx - 1];
                continue;
            }
            upper[1][j - sx] = min({upper[1][j - sx - 1], upper[0][j - sx], upper[0][j - sx - 1]}) + 1;
        }
    }

    vector<vector<int>> lower(2, vector<int>(len));

    for (int i = ex; i >= sx; i--) {
        lower[0][i - sx] = ex - i;
    }

    for (int i = ey - 1; i >= my + 1; i--) {
        for (int j = ex; j >= sx; j--) {
            lower[1][j - sx] = lower[0][j - sx];
        }

        lower[0][ex - sx] = ey - i;

        for (int j = ex - 1; j >= sx; j--) {
            if (S[i] == E[j]) {
                lower[0][j - sx] = lower[1][j - sx + 1];
                continue;
            }
            lower[0][j - sx] = min({lower[0][j - sx + 1], lower[1][j - sx], lower[1][j - sx + 1]}) + 1;
        }
    }

    int mn = 987654321;
    int index = -1;
    int dir = -1;

    for (int i = sx; i <= ex; i++) {
        int sum = upper[1][i - sx] + lower[0][i - sx] + 1;
        if (sum >= mn) continue;

        mn = sum;
        index = i;
        dir = 1;
    }

    int next = 0;

    for (int i = sx; i < ex; i++) {
        int sum = upper[1][i - sx] + lower[0][i - sx + 1] + 1 - (E[i] == S[my]);
        if (sum >= mn) continue;

        mn = sum;
        index = i;
        dir = 2 + (E[i] == S[my]);
        next = 1;
    }

    solve(sy, sx, my, index);

    if (dir == 1) {
        cout << "d " << S[my];
    } else if (dir == 2) {
        cout << "m " << E[index];
    } else if (dir == 3) {
        cout << "c " << E[index];
    }

    cout << '\n';

    solve(my + 1, index + next, ey, ex);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S >> E;

    solve(0, 0, S.size(), E.size());

    return 0;
}
