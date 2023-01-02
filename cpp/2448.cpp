#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<bool>> v;

void drawTriangle(int y, int x) {
    v[y][x] = true;
    v[y + 1][x - 1] = v[y+1][x + 1] = true;
    for (int i = x - 2; i <= x + 2; i++) v[y + 2][i] = true;
}

void solve(int y, int x, int size) {
    if (size == 3) drawTriangle(y, x);
    else {
        size /= 2;
        solve(y, x, size);
        solve(y + size, x - size, size);
        solve(y + size, x + size, size);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    v = vector(n, vector<bool>(n * 2 - 1));

    solve(0, n - 1, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n * 2 - 1; j++) {
            cout << (v[i][j] ? '*' : ' ');
        }
        cout << '\n';
    }
    return 0;
}
