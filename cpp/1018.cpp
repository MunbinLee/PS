#include <iostream>
#include <vector>

using namespace std;

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))

vector<string> v;

int count(int y, int x) {
    int cnt[2]{};

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char c = ((i + j) % 2) ? 'B' : 'W';
            for (int k = 0; k < 2; k++) {
                if (v[y + i][x + j] != c) cnt[k]++;
                c = (c == 'B') ? 'W' : 'B';
            }
        }
    }
    return min(cnt[0], cnt[1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    REP(i, n) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    int res = INT32_MAX;

    for (int i = 0; i + 8 <= n; i++) {
        for (int j = 0; j + 8 <= m; j++) {
            res = min(res, count(i, j));
        }
    }

    cout << res;
    return 0;
}
