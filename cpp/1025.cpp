#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

int n, m;
int mx = -1;
vector<vector<int>> v;

bool isSquare(int num) {
    int root = sqrt(num);
    if (root * root == num) return true;
    return false;
}

void solve(int ra, int rd, int ca, int cd) {
    int num = 0;
    while (true) {
        if (ra < 0 || ra >= n) return;
        if (ca < 0 || ca >= m) return;
        if (rd <= -n || rd >= n) return;
        if (cd <= -m || cd >= m) return;
        num = num * 10 + v[ra][ca];
        if (isSquare(num)) {
            if (num > mx) mx = num;
        }
        if (rd == 0 && cd == 0) return;
        ra += rd;
        ca += cd;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    v = vector(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        int nums;
        cin >> nums;
        for (int j = m - 1; j >= 0; j--) {
            v[i][j] = nums % 10;
            nums /= 10;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = -n + 1; j < n; j++) {
            for (int k = 0; k < m; k++) {
                for (int l = -m + 1; l < m; l++) {
                    solve(i, j, k, l);
                }
            }
        }
    }

    cout << mx;
    return 0;
}
